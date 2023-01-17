#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/lexical_cast.hpp>
class Database
{
    public:
    virtual int get_population (const std::string& name )=0;
};

class SingletonDataBase : public Database
{
    SingletonDataBase(){
        // read data from database
        std::cout << "Initializing database" << std::endl;

        std::ifstream ifs("capitals.txt");
        std::string s, s2;
        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = boost::lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
    std::map<std::string, int> captials;
    public:
    SingletonDataBase(SingletonDataBase const&)=delete;
    void operator =(SingletonDataBase const&)=delete;

    static SingletonDataBase& get()
    {
        static SingletonDataBase db;
        return db;
    }
    int get_population(const std::string& name) override;
     /*
  static SingletonDatabase* get_instance()
  {
    if (!instance)
      instance = new SingletonDatabase;
    return instance; // atexit
  }
  */
};

class DummyDatabase : public Database
{
  std::map<std::string, int> capitals;
public:


    DummyDatabase()
    {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }

    int get_population(const std::string& name) override {
        return capitals[name];
    }
};


struct SingletonRecordFinder
{
  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for (auto& name : names)
       result += SingletonDatabase::get().get_population(name);
    return result;
  }
};

struct ConfigurableRecordFinder
{
  explicit ConfigurableRecordFinder(Database& db)
    : db{db}
  {
  }

  int total_population(std::vector<std::string> names) const
  {
    int result = 0;
    for (auto& name : names)
      result += db.get_population(name);
    return result;
  }

  Database& db;
};