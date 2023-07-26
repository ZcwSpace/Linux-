
helloworld.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 83 ec 10          	sub    $0x10,%rsp
   8:	c7 45 fc 64 00 00 00 	movl   $0x64,-0x4(%rbp)
   f:	bf 00 00 00 00       	mov    $0x0,%edi
  14:	e8 00 00 00 00       	callq  19 <main+0x19>
  19:	b8 00 00 00 00       	mov    $0x0,%eax
  1e:	c9                   	leaveq 
  1f:	c3                   	retq   

Disassembly of section .rodata:

0000000000000000 <.rodata>:
   0:	48                   	rex.W
   1:	65 6c                	gs insb (%dx),%es:(%rdi)
   3:	6c                   	insb   (%dx),%es:(%rdi)
   4:	6f                   	outsl  %ds:(%rsi),(%dx)
   5:	20 57 6f             	and    %dl,0x6f(%rdi)
   8:	72 6c                	jb     76 <main+0x76>
   a:	64                   	fs
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	00 47 43             	add    %al,0x43(%rdi)
   3:	43 3a 20             	rex.XB cmp (%r8),%spl
   6:	28 55 6f             	sub    %dl,0x6f(%rbp)
   9:	73 20                	jae    2b <main+0x2b>
   b:	38 2e                	cmp    %ch,(%rsi)
   d:	33 2e                	xor    (%rsi),%ebp
   f:	30 2e                	xor    %ch,(%rsi)
  11:	33 2d 33 2b 72 65    	xor    0x65722b33(%rip),%ebp        # 65722b4a <main+0x65722b4a>
  17:	62                   	(bad)  
  18:	75 69                	jne    83 <main+0x83>
  1a:	6c                   	insb   (%dx),%es:(%rdi)
  1b:	64 29 20             	sub    %esp,%fs:(%rax)
  1e:	38 2e                	cmp    %ch,(%rsi)
  20:	33 2e                	xor    (%rsi),%ebp
  22:	30 00                	xor    %al,(%rax)

Disassembly of section .eh_frame:

0000000000000000 <.eh_frame>:
   0:	14 00                	adc    $0x0,%al
   2:	00 00                	add    %al,(%rax)
   4:	00 00                	add    %al,(%rax)
   6:	00 00                	add    %al,(%rax)
   8:	01 7a 52             	add    %edi,0x52(%rdx)
   b:	00 01                	add    %al,(%rcx)
   d:	78 10                	js     1f <.eh_frame+0x1f>
   f:	01 1b                	add    %ebx,(%rbx)
  11:	0c 07                	or     $0x7,%al
  13:	08 90 01 00 00 1c    	or     %dl,0x1c000001(%rax)
  19:	00 00                	add    %al,(%rax)
  1b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  1e:	00 00                	add    %al,(%rax)
  20:	00 00                	add    %al,(%rax)
  22:	00 00                	add    %al,(%rax)
  24:	20 00                	and    %al,(%rax)
  26:	00 00                	add    %al,(%rax)
  28:	00 41 0e             	add    %al,0xe(%rcx)
  2b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  31:	5b                   	pop    %rbx
  32:	0c 07                	or     $0x7,%al
  34:	08 00                	or     %al,(%rax)
	...
