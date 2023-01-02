template <class To, class From> 
To safe_reinterpret_cast(From from) 
{ 
 assert(sizeof(From) <= sizeof(To)); 
 return reinterpret_cast<To>(from); 
} 