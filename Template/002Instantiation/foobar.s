	.file	"foobar.cpp"
	.text
	.section	.text$_ZN4TestIiE3fooEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4TestIiE3fooEv
	.def	_ZN4TestIiE3fooEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4TestIiE3fooEv
_ZN4TestIiE3fooEv:
.LFB4:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z6squareIiET_S0_,"x"
	.linkonce discard
	.globl	_Z6squareIiET_S0_
	.def	_Z6squareIiET_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6squareIiET_S0_
_Z6squareIiET_S0_:
.LFB5:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	16(%rbp), %eax
	imull	16(%rbp), %eax
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB3:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
