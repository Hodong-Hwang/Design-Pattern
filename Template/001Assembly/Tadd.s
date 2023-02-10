	.file	"Tadd.cpp"
	.text
	.globl	_Z3addii
	.def	_Z3addii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3addii
_Z3addii:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %edx
	movl	24(%rbp), %eax
	addl	%edx, %eax
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$3, %ecx
	call	_Z6squareIiET_S0_
	movq	.LC0(%rip), %rax
	movq	%rax, %xmm0
	call	_Z6squareIdET_S0_
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z6squareIiET_S0_,"x"
	.linkonce discard
	.globl	_Z6squareIiET_S0_
	.def	_Z6squareIiET_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6squareIiET_S0_
_Z6squareIiET_S0_:
.LFB3:
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
	.section	.text$_Z6squareIdET_S0_,"x"
	.linkonce discard
	.globl	_Z6squareIdET_S0_
	.def	_Z6squareIdET_S0_;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6squareIdET_S0_
_Z6squareIdET_S0_:
.LFB4:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movsd	%xmm0, 16(%rbp)
	movsd	16(%rbp), %xmm0
	mulsd	16(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	1717986918
	.long	1074423398
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
