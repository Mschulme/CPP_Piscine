	.file	"parallel_benchmark.cpp"
	.text
	.section	.text._ZNSt13random_deviceC2Ev,"axG",@progbits,_ZNSt13random_deviceC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt13random_deviceC2Ev
	.type	_ZNSt13random_deviceC2Ev, @function
_ZNSt13random_deviceC2Ev:
.LFB7232:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA7232
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$56, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leaq	16(%rsp), %rbx
	movl	$27765, %eax
	movq	%rsp, %rsi
	movq	%rbx, (%rsp)
	movl	$1634100580, 16(%rsp)
	movw	%ax, 20(%rsp)
	movb	$116, 22(%rsp)
	movq	$7, 8(%rsp)
	movb	$0, 23(%rsp)
.LEHB0:
	call	_ZNSt13random_device7_M_initERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE@PLT
.LEHE0:
	movq	(%rsp), %rdi
	cmpq	%rbx, %rdi
	je	.L1
	movq	16(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L1:
	movq	40(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L11
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L11:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
.L6:
	endbr64
	movq	%rax, %rbp
.L3:
	movq	(%rsp), %rdi
	cmpq	%rbx, %rdi
	je	.L7
	movq	16(%rsp), %rax
	leaq	1(%rax), %rsi
	vzeroupper
	call	_ZdlPvm@PLT
.L4:
	movq	%rbp, %rdi
.LEHB1:
	call	_Unwind_Resume@PLT
.LEHE1:
.L7:
	vzeroupper
	jmp	.L4
	.cfi_endproc
.LFE7232:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNSt13random_deviceC2Ev,"aG",@progbits,_ZNSt13random_deviceC5Ev,comdat
.LLSDA7232:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE7232-.LLSDACSB7232
.LLSDACSB7232:
	.uleb128 .LEHB0-.LFB7232
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L6-.LFB7232
	.uleb128 0
	.uleb128 .LEHB1-.LFB7232
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE7232:
	.section	.text._ZNSt13random_deviceC2Ev,"axG",@progbits,_ZNSt13random_deviceC5Ev,comdat
	.size	_ZNSt13random_deviceC2Ev, .-_ZNSt13random_deviceC2Ev
	.weak	_ZNSt13random_deviceC1Ev
	.set	_ZNSt13random_deviceC1Ev,_ZNSt13random_deviceC2Ev
	.section	.text._ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv,"axG",@progbits,_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv
	.type	_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv, @function
_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv:
.LFB9264:
	.cfi_startproc
	endbr64
	vmovdqa	.LC0(%rip), %ymm3
	vmovdqa	.LC1(%rip), %ymm4
	vmovdqa	.LC2(%rip), %ymm5
	vmovdqa	.LC3(%rip), %ymm6
	movq	%rdi, %rax
	leaq	1792(%rdi), %rcx
	movq	%rdi, %rdx
	vpxor	%xmm7, %xmm7, %xmm7
	.p2align 4,,10
	.p2align 3
.L13:
	vpand	8(%rdx), %ymm4, %ymm1
	vpand	(%rdx), %ymm3, %ymm0
	addq	$32, %rdx
	vpor	%ymm1, %ymm0, %ymm0
	vpsrlq	$1, %ymm0, %ymm1
	vpand	%ymm5, %ymm0, %ymm0
	vpxor	3144(%rdx), %ymm1, %ymm1
	vpcmpeqq	%ymm7, %ymm0, %ymm0
	vpxor	%ymm6, %ymm1, %ymm2
	vpblendvb	%ymm0, %ymm1, %ymm2, %ymm0
	vmovdqu	%ymm0, -32(%rdx)
	cmpq	%rdx, %rcx
	jne	.L13
	vmovdqa	.LC4(%rip), %xmm0
	vmovdqa	.LC5(%rip), %xmm1
	vpand	1792(%rax), %xmm0, %xmm0
	vpand	1800(%rax), %xmm1, %xmm1
	movq	1808(%rax), %rdx
	vpor	%xmm1, %xmm0, %xmm0
	movq	1816(%rax), %rcx
	vpsrlq	$1, %xmm0, %xmm1
	vpand	.LC6(%rip), %xmm0, %xmm0
	andl	$2147483647, %ecx
	vpxor	4968(%rax), %xmm1, %xmm1
	andq	$-2147483648, %rdx
	vpxor	%xmm7, %xmm7, %xmm7
	orq	%rcx, %rdx
	vpcmpeqq	%xmm7, %xmm0, %xmm0
	movq	%rdx, %rcx
	vpxor	.LC7(%rip), %xmm1, %xmm2
	shrq	%rcx
	vpblendvb	%xmm0, %xmm1, %xmm2, %xmm0
	xorq	4984(%rax), %rcx
	andl	$1, %edx
	vmovdqu	%xmm0, 1792(%rax)
	je	.L16
	movl	$2567483615, %edx
	xorq	%rdx, %rcx
.L16:
	movq	%rcx, 1808(%rax)
	leaq	1816(%rax), %rdx
	leaq	4984(%rax), %rcx
	vpxor	%xmm2, %xmm2, %xmm2
.L15:
	vpand	8(%rdx), %ymm4, %ymm1
	vpand	(%rdx), %ymm3, %ymm0
	addq	$32, %rdx
	vpor	%ymm1, %ymm0, %ymm0
	vpsrlq	$1, %ymm0, %ymm1
	vpand	%ymm5, %ymm0, %ymm0
	vpxor	-1848(%rdx), %ymm1, %ymm1
	vpcmpeqq	%ymm2, %ymm0, %ymm0
	vpxor	%ymm6, %ymm1, %ymm7
	vpblendvb	%ymm0, %ymm1, %ymm7, %ymm0
	vmovdqu	%ymm0, -32(%rdx)
	cmpq	%rcx, %rdx
	jne	.L15
	movq	4984(%rax), %rdx
	movq	(%rax), %rcx
	andq	$-2147483648, %rdx
	andl	$2147483647, %ecx
	orq	%rcx, %rdx
	movq	%rdx, %rcx
	shrq	%rcx
	xorq	3168(%rax), %rcx
	andl	$1, %edx
	je	.L17
	movl	$2567483615, %edx
	xorq	%rdx, %rcx
.L17:
	movq	%rcx, 4984(%rax)
	movq	$0, 4992(%rax)
	vzeroupper
	ret
	.cfi_endproc
.LFE9264:
	.size	_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv, .-_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv
	.text
	.align 2
	.p2align 4
	.type	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEiRT_RKNS0_10param_typeE.isra.0, @function
_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEiRT_RKNS0_10param_typeE.isra.0:
.LFB9427:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movslq	%esi, %rax
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movslq	%edx, %r13
	subq	%rax, %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rdi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rax, %rbp
	movl	$4294967294, %eax
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	cmpq	%rax, %r13
	jbe	.L40
	movl	$4294967295, %eax
	cmpq	%rax, %r13
	je	.L30
.L38:
	movl	$-1, %edx
	xorl	%esi, %esi
	movq	%r12, %rdi
	call	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEiRT_RKNS0_10param_typeE.isra.0
	movq	%rax, %rbx
	movq	4992(%r12), %rax
	salq	$32, %rbx
	cmpq	$623, %rax
	jbe	.L31
	movq	%r12, %rdi
	call	_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv
	movq	4992(%r12), %rax
.L31:
	leaq	1(%rax), %rdx
	movq	(%r12,%rax,8), %rax
	movq	%rdx, 4992(%r12)
	movq	%rax, %rdx
	shrq	$11, %rdx
	movl	%edx, %edx
	xorq	%rdx, %rax
	movq	%rax, %rdx
	salq	$7, %rdx
	andl	$2636928640, %edx
	xorq	%rdx, %rax
	movq	%rax, %rdx
	salq	$15, %rdx
	andl	$4022730752, %edx
	xorq	%rdx, %rax
	movq	%rax, %rdx
	shrq	$18, %rdx
	xorq	%rdx, %rax
	addq	%rax, %rbx
	setc	%al
	movzbl	%al, %eax
	cmpq	%rbx, %r13
	jb	.L38
	testq	%rax, %rax
	jne	.L38
.L29:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	leal	0(%rbp,%rbx), %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L40:
	.cfi_restore_state
	movq	4992(%rdi), %rax
	incq	%r13
	movl	%r13d, %r15d
	cmpq	$623, %rax
	ja	.L41
.L25:
	movq	(%r12,%rax,8), %rbx
	leaq	1(%rax), %rcx
	movq	%rbx, %rax
	shrq	$11, %rax
	movl	%eax, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	salq	$7, %rax
	andl	$2636928640, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	salq	$15, %rax
	andl	$4022730752, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	shrq	$18, %rax
	xorq	%rax, %rbx
	imulq	%r13, %rbx
	movq	%rcx, 4992(%r12)
	cmpl	%ebx, %r13d
	jbe	.L26
	movl	%r13d, %eax
	negl	%eax
	xorl	%edx, %edx
	divl	%r15d
	movl	%edx, %r14d
	cmpl	%edx, %ebx
	jb	.L28
	jmp	.L26
	.p2align 4,,10
	.p2align 3
.L27:
	movq	(%r12,%rax,8), %rbx
	leaq	1(%rax), %rcx
	movq	%rbx, %rax
	shrq	$11, %rax
	movl	%eax, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	salq	$7, %rax
	andl	$2636928640, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	salq	$15, %rax
	andl	$4022730752, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	shrq	$18, %rax
	xorq	%rax, %rbx
	imulq	%r13, %rbx
	movq	%rcx, 4992(%r12)
	cmpl	%ebx, %r14d
	jbe	.L26
.L28:
	movq	%rcx, %rax
	cmpq	$623, %rcx
	jbe	.L27
	movq	%r12, %rdi
	call	_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv
	movq	4992(%r12), %rax
	jmp	.L27
	.p2align 4,,10
	.p2align 3
.L26:
	shrq	$32, %rbx
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L30:
	movq	4992(%rdi), %rax
	cmpq	$623, %rax
	ja	.L42
.L35:
	movq	(%r12,%rax,8), %rbx
	leaq	1(%rax), %rdx
	movq	%rbx, %rax
	shrq	$11, %rax
	movl	%eax, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	salq	$7, %rax
	andl	$2636928640, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	salq	$15, %rax
	andl	$4022730752, %eax
	xorq	%rax, %rbx
	movq	%rbx, %rax
	shrq	$18, %rax
	movq	%rdx, 4992(%r12)
	xorq	%rax, %rbx
	jmp	.L29
	.p2align 4,,10
	.p2align 3
.L41:
	call	_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv
	movq	4992(%r12), %rax
	jmp	.L25
	.p2align 4,,10
	.p2align 3
.L42:
	call	_ZNSt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EE11_M_gen_randEv
	movq	4992(%r12), %rax
	jmp	.L35
	.cfi_endproc
.LFE9427:
	.size	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEiRT_RKNS0_10param_typeE.isra.0, .-_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEiRT_RKNS0_10param_typeE.isra.0
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC8:
	.string	"std::accumulate (sequential)"
.LC9:
	.string	"Result: "
.LC10:
	.string	", Time: "
.LC11:
	.string	" ms\n"
.LC12:
	.string	"std::reduce(seq)"
.LC13:
	.string	"std::reduce(par)"
.LC14:
	.string	"std::reduce(par_unseq)"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB15:
	.section	.text.startup,"ax",@progbits
.LHOTB15:
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB8348:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA8348
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	andq	$-32, %rsp
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$1856, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movl	$2000000000, %edi
	movq	%fs:40, %rax
	movq	%rax, 10040(%rsp)
	xorl	%eax, %eax
.LEHB2:
	call	_Znwm@PLT
.LEHE2:
	leaq	4(%rax), %rdi
	leaq	2000000000(%rax), %rbx
	movl	$0, (%rax)
	movq	%rax, %r15
	cmpq	%rbx, %rdi
	je	.L44
	movl	$1999999996, %edx
	xorl	%esi, %esi
	call	memset@PLT
.L44:
	leaq	32(%rsp), %r14
	movq	%r14, %rdi
	movq	%r14, 24(%rsp)
.LEHB3:
	call	_ZNSt13random_deviceC1Ev
.LEHE3:
	movq	%r14, %rdi
.LEHB4:
	call	_ZNSt13random_device9_M_getvalEv@PLT
	movl	%eax, %ecx
	movq	%rcx, 5040(%rsp)
	movl	$1, %edx
	leaq	5040(%rsp), %r12
	.p2align 4,,10
	.p2align 3
.L45:
	movq	%rcx, %rax
	shrq	$30, %rax
	xorq	%rcx, %rax
	imulq	$1812433253, %rax, %rax
	leal	(%rax,%rdx), %ecx
	movq	%rcx, (%r12,%rdx,8)
	incq	%rdx
	cmpq	$624, %rdx
	jne	.L45
	movq	$624, 10032(%rsp)
	movq	%r15, %r14
	movq	%r15, %r13
	.p2align 4,,10
	.p2align 3
.L46:
	movl	$10, %edx
	movl	$1, %esi
	movq	%r12, %rdi
	call	_ZNSt24uniform_int_distributionIiEclISt23mersenne_twister_engineImLm32ELm624ELm397ELm31ELm2567483615ELm11ELm4294967295ELm7ELm2636928640ELm15ELm4022730752ELm18ELm1812433253EEEEiRT_RKNS0_10param_typeE.isra.0
	movl	%eax, 0(%r13)
	addq	$4, %r13
	cmpq	%r13, %rbx
	jne	.L46
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, %r13
	vpxor	%xmm1, %xmm1, %xmm1
	movq	%r15, %rax
	.p2align 4,,10
	.p2align 3
.L48:
	vmovdqu	(%rax), %ymm0
	addq	$32, %rax
	vpmovsxdq	%xmm0, %ymm2
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm1, %ymm2, %ymm1
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm1, %ymm0, %ymm1
	cmpq	%rax, %rbx
	jne	.L48
	vmovdqa	%xmm1, %xmm0
	vextracti128	$0x1, %ymm1, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %r12
	vzeroupper
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	subq	%r13, %rax
	movabsq	$4835703278458516699, %rdx
	movq	%rax, %rcx
	imulq	%rdx
	sarq	$63, %rcx
	movq	_ZSt4cout(%rip), %rax
	sarq	$18, %rdx
	subq	%rcx, %rdx
	movq	%rdx, 16(%rsp)
	movq	-24(%rax), %rdx
	leaq	_ZSt4cout(%rip), %r13
	movq	$38, 16(%r13,%rdx)
	leaq	.LC8(%rip), %rsi
	movl	$28, %edx
	movq	-24(%rax), %rdi
	addq	%r13, %rdi
	movl	24(%rdi), %eax
	andb	$79, %al
	orl	$32, %eax
	movl	%eax, 24(%rdi)
	movq	%r13, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	$8, %edx
	leaq	.LC9(%rip), %rsi
	movq	%r13, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r12, %rsi
	movq	%r13, %rdi
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	movl	$8, %edx
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	movq	%rax, %r12
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	16(%rsp), %rsi
	movq	%r12, %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	movl	$4, %edx
	leaq	.LC11(%rip), %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, 16(%rsp)
	xorl	%r12d, %r12d
	movq	%r15, %rax
	.p2align 4,,10
	.p2align 3
.L50:
	movslq	(%rax), %rcx
	movslq	4(%rax), %rdx
	movslq	8(%rax), %rsi
	addq	%rcx, %rdx
	movslq	12(%rax), %rcx
	addq	$16, %rax
	addq	%rsi, %rcx
	addq	%rcx, %rdx
	addq	%rdx, %r12
	movq	%rbx, %rdx
	subq	%rax, %rdx
	cmpq	$12, %rdx
	jg	.L50
	cmpq	%rax, %rbx
	je	.L51
	leaq	1999999996(%r15), %rcx
	subq	%rax, %rcx
	movq	%rcx, %rsi
	shrq	$2, %rsi
	movq	%rax, %rdx
	leaq	1(%rsi), %rdi
	cmpq	$24, %rcx
	jbe	.L75
	movq	%rdi, %rcx
	shrq	$3, %rcx
	salq	$5, %rcx
	addq	%rax, %rcx
	vpxor	%xmm1, %xmm1, %xmm1
	.p2align 4,,10
	.p2align 3
.L53:
	vmovdqu	(%rdx), %ymm0
	addq	$32, %rdx
	vpmovsxdq	%xmm0, %ymm2
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm1, %ymm2, %ymm1
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm1, %ymm0, %ymm1
	cmpq	%rcx, %rdx
	jne	.L53
	vmovdqa	%xmm1, %xmm0
	vextracti128	$0x1, %ymm1, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	movq	%rdi, %rcx
	vmovq	%xmm0, %rdx
	andq	$-8, %rcx
	addq	%rdx, %r12
	leaq	(%rax,%rcx,4), %rdx
	cmpq	%rcx, %rdi
	je	.L95
	vzeroupper
.L52:
	subq	%rcx, %rsi
	leaq	1(%rsi), %rdi
	cmpq	$2, %rsi
	jbe	.L55
	vmovdqu	(%rax,%rcx,4), %xmm1
	vpmovsxdq	%xmm1, %xmm0
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxdq	%xmm1, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	addq	%rax, %r12
	movq	%rdi, %rax
	andq	$-4, %rax
	leaq	(%rdx,%rax,4), %rdx
	cmpq	%rax, %rdi
	je	.L51
.L55:
	movslq	(%rdx), %rax
	addq	%rax, %r12
	leaq	4(%rdx), %rax
	cmpq	%rax, %rbx
	je	.L51
	movslq	4(%rdx), %rax
	addq	%rax, %r12
	leaq	8(%rdx), %rax
	cmpq	%rax, %rbx
	je	.L51
	movslq	8(%rdx), %rax
	addq	%rax, %r12
.L51:
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	subq	16(%rsp), %rax
	movabsq	$4835703278458516699, %rdx
	movq	%rax, %rcx
	imulq	%rdx
	sarq	$63, %rcx
	movq	_ZSt4cout(%rip), %rax
	sarq	$18, %rdx
	subq	%rcx, %rdx
	movq	%rdx, 16(%rsp)
	movq	-24(%rax), %rdx
	leaq	.LC12(%rip), %rsi
	movq	$38, 16(%r13,%rdx)
	movl	$16, %edx
	movq	-24(%rax), %rdi
	addq	%r13, %rdi
	movl	24(%rdi), %eax
	andb	$79, %al
	orl	$32, %eax
	movl	%eax, 24(%rdi)
	movq	%r13, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	$8, %edx
	leaq	.LC9(%rip), %rsi
	movq	%r13, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r12, %rsi
	movq	%r13, %rdi
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	movl	$8, %edx
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	movq	%rax, %r12
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	16(%rsp), %rsi
	movq	%r12, %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	movl	$4, %edx
	leaq	.LC11(%rip), %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, 16(%rsp)
	xorl	%r12d, %r12d
	movq	%r15, %rax
	.p2align 4,,10
	.p2align 3
.L58:
	movslq	(%rax), %rcx
	movslq	4(%rax), %rdx
	movslq	8(%rax), %rsi
	addq	%rcx, %rdx
	movslq	12(%rax), %rcx
	addq	$16, %rax
	addq	%rsi, %rcx
	addq	%rcx, %rdx
	addq	%rdx, %r12
	movq	%rbx, %rdx
	subq	%rax, %rdx
	cmpq	$12, %rdx
	jg	.L58
	cmpq	%rax, %rbx
	je	.L59
	leaq	1999999996(%r15), %rcx
	subq	%rax, %rcx
	movq	%rcx, %rsi
	shrq	$2, %rsi
	movq	%rax, %rdx
	leaq	1(%rsi), %rdi
	cmpq	$24, %rcx
	jbe	.L77
	movq	%rdi, %rcx
	shrq	$3, %rcx
	salq	$5, %rcx
	addq	%rax, %rcx
	vpxor	%xmm1, %xmm1, %xmm1
	.p2align 4,,10
	.p2align 3
.L61:
	vmovdqu	(%rdx), %ymm0
	addq	$32, %rdx
	vpmovsxdq	%xmm0, %ymm2
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm1, %ymm2, %ymm1
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm1, %ymm0, %ymm1
	cmpq	%rcx, %rdx
	jne	.L61
	vmovdqa	%xmm1, %xmm0
	vextracti128	$0x1, %ymm1, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	movq	%rdi, %rcx
	vmovq	%xmm0, %rdx
	andq	$-8, %rcx
	addq	%rdx, %r12
	leaq	(%rax,%rcx,4), %rdx
	cmpq	%rcx, %rdi
	je	.L96
	vzeroupper
.L60:
	subq	%rcx, %rsi
	leaq	1(%rsi), %rdi
	cmpq	$2, %rsi
	jbe	.L63
	vmovdqu	(%rax,%rcx,4), %xmm1
	vpmovsxdq	%xmm1, %xmm0
	vpsrldq	$8, %xmm1, %xmm1
	vpmovsxdq	%xmm1, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %rax
	addq	%rax, %r12
	movq	%rdi, %rax
	andq	$-4, %rax
	leaq	(%rdx,%rax,4), %rdx
	cmpq	%rdi, %rax
	je	.L59
.L63:
	movslq	(%rdx), %rax
	addq	%rax, %r12
	leaq	4(%rdx), %rax
	cmpq	%rax, %rbx
	je	.L59
	movslq	4(%rdx), %rax
	addq	%rax, %r12
	leaq	8(%rdx), %rax
	cmpq	%rax, %rbx
	je	.L59
	movslq	8(%rdx), %rax
	addq	%rax, %r12
.L59:
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	subq	16(%rsp), %rax
	movabsq	$4835703278458516699, %rdx
	movq	%rax, %rcx
	imulq	%rdx
	sarq	$63, %rcx
	movq	_ZSt4cout(%rip), %rax
	sarq	$18, %rdx
	subq	%rcx, %rdx
	movq	%rdx, 16(%rsp)
	movq	-24(%rax), %rdx
	leaq	.LC13(%rip), %rsi
	movq	$38, 16(%r13,%rdx)
	movl	$16, %edx
	movq	-24(%rax), %rdi
	addq	%r13, %rdi
	movl	24(%rdi), %eax
	andb	$79, %al
	orl	$32, %eax
	movl	%eax, 24(%rdi)
	movq	%r13, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	$8, %edx
	leaq	.LC9(%rip), %rsi
	movq	%r13, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r12, %rsi
	movq	%r13, %rdi
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	movl	$8, %edx
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	movq	%rax, %r12
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	16(%rsp), %rsi
	movq	%r12, %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	movl	$4, %edx
	leaq	.LC11(%rip), %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	%rax, %rdx
	vpxor	%xmm1, %xmm1, %xmm1
	.p2align 4,,10
	.p2align 3
.L67:
	vmovdqu	(%r14), %ymm0
	addq	$32, %r14
	vpmovsxdq	%xmm0, %ymm2
	vextracti128	$0x1, %ymm0, %xmm0
	vpaddq	%ymm1, %ymm2, %ymm1
	vpmovsxdq	%xmm0, %ymm0
	vpaddq	%ymm1, %ymm0, %ymm1
	cmpq	%rbx, %r14
	jne	.L67
	vextracti128	$0x1, %ymm1, %xmm0
	vpaddq	%xmm1, %xmm0, %xmm0
	vpsrldq	$8, %xmm0, %xmm1
	vpaddq	%xmm1, %xmm0, %xmm0
	vmovq	%xmm0, %r12
	movq	%rdx, 16(%rsp)
	vzeroupper
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	16(%rsp), %rdx
	leaq	.LC14(%rip), %rsi
	subq	%rdx, %rax
	movabsq	$4835703278458516699, %rdx
	movq	%rax, %rcx
	imulq	%rdx
	sarq	$63, %rcx
	movq	_ZSt4cout(%rip), %rax
	sarq	$18, %rdx
	subq	%rcx, %rdx
	movq	%rdx, %r14
	movq	-24(%rax), %rdx
	movq	%r13, %rdi
	movq	$38, 16(%r13,%rdx)
	movq	-24(%rax), %rdx
	addq	%r13, %rdx
	movl	24(%rdx), %eax
	andb	$79, %al
	orl	$32, %eax
	movl	%eax, 24(%rdx)
	movl	$22, %edx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	$8, %edx
	leaq	.LC9(%rip), %rsi
	movq	%r13, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r12, %rsi
	movq	%r13, %rdi
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	movl	$8, %edx
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	movq	%rax, %r12
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rsi
	movq	%r12, %rdi
	call	_ZNSo9_M_insertIlEERSoT_@PLT
	movq	%rax, %rdi
	movl	$4, %edx
	leaq	.LC11(%rip), %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.LEHE4:
	movq	24(%rsp), %rdi
	call	_ZNSt13random_device7_M_finiEv@PLT
	movl	$2000000000, %esi
	movq	%r15, %rdi
	call	_ZdlPvm@PLT
	movq	10040(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L97
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	xorl	%eax, %eax
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L95:
	.cfi_restore_state
	vzeroupper
	jmp	.L51
.L96:
	vzeroupper
	jmp	.L59
.L77:
	xorl	%ecx, %ecx
	jmp	.L60
.L75:
	xorl	%ecx, %ecx
	jmp	.L52
.L97:
	call	__stack_chk_fail@PLT
.L81:
	endbr64
	movq	%rax, %r12
	jmp	.L71
.L80:
	endbr64
	movq	%rax, %r12
	vzeroupper
	jmp	.L72
	.section	.gcc_except_table,"a",@progbits
.LLSDA8348:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE8348-.LLSDACSB8348
.LLSDACSB8348:
	.uleb128 .LEHB2-.LFB8348
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB8348
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L80-.LFB8348
	.uleb128 0
	.uleb128 .LEHB4-.LFB8348
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L81-.LFB8348
	.uleb128 0
.LLSDACSE8348:
	.section	.text.startup
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC8348
	.type	main.cold, @function
main.cold:
.LFSB8348:
.L71:
	.cfi_def_cfa 6, 16
	.cfi_offset 3, -56
	.cfi_offset 6, -16
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	24(%rsp), %rdi
	vzeroupper
	call	_ZNSt13random_device7_M_finiEv@PLT
.L72:
	movq	%r15, %rdi
	movl	$2000000000, %esi
	call	_ZdlPvm@PLT
	movq	%r12, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
	.cfi_endproc
.LFE8348:
	.section	.gcc_except_table
.LLSDAC8348:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC8348-.LLSDACSBC8348
.LLSDACSBC8348:
	.uleb128 .LEHB5-.LCOLDB15
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSEC8348:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold, .-main.cold
.LCOLDE15:
	.section	.text.startup
.LHOTE15:
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB9420:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	leaq	__dso_handle(%rip), %rdx
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE9420:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst32,"aM",@progbits,32
	.align 32
.LC0:
	.quad	-2147483648
	.quad	-2147483648
	.quad	-2147483648
	.quad	-2147483648
	.align 32
.LC1:
	.quad	2147483647
	.quad	2147483647
	.quad	2147483647
	.quad	2147483647
	.align 32
.LC2:
	.quad	1
	.quad	1
	.quad	1
	.quad	1
	.align 32
.LC3:
	.quad	2567483615
	.quad	2567483615
	.quad	2567483615
	.quad	2567483615
	.set	.LC4,.LC0
	.set	.LC5,.LC1
	.set	.LC6,.LC2
	.set	.LC7,.LC3
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
