
helloworld：     文件格式 elf64-x86-64


Disassembly of section .interp:

00000000004002a8 <.interp>:
  4002a8:	2f                   	(bad)  
  4002a9:	6c                   	insb   (%dx),%es:(%rdi)
  4002aa:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  4002b1:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  4002b6:	78 2d                	js     4002e5 <printf@plt-0xd4b>
  4002b8:	78 38                	js     4002f2 <printf@plt-0xd3e>
  4002ba:	36 2d 36 34 2e 73    	ss sub $0x732e3436,%eax
  4002c0:	6f                   	outsl  %ds:(%rsi),(%dx)
  4002c1:	2e 32 00             	xor    %cs:(%rax),%al

Disassembly of section .note.ABI-tag:

00000000004002c4 <.note.ABI-tag>:
  4002c4:	04 00                	add    $0x0,%al
  4002c6:	00 00                	add    %al,(%rax)
  4002c8:	10 00                	adc    %al,(%rax)
  4002ca:	00 00                	add    %al,(%rax)
  4002cc:	01 00                	add    %eax,(%rax)
  4002ce:	00 00                	add    %al,(%rax)
  4002d0:	47                   	rex.RXB
  4002d1:	4e 55                	rex.WRX push %rbp
  4002d3:	00 00                	add    %al,(%rax)
  4002d5:	00 00                	add    %al,(%rax)
  4002d7:	00 03                	add    %al,(%rbx)
  4002d9:	00 00                	add    %al,(%rax)
  4002db:	00 02                	add    %al,(%rdx)
  4002dd:	00 00                	add    %al,(%rax)
  4002df:	00 00                	add    %al,(%rax)
  4002e1:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

00000000004002e4 <.note.gnu.build-id>:
  4002e4:	04 00                	add    $0x0,%al
  4002e6:	00 00                	add    %al,(%rax)
  4002e8:	14 00                	adc    $0x0,%al
  4002ea:	00 00                	add    %al,(%rax)
  4002ec:	03 00                	add    (%rax),%eax
  4002ee:	00 00                	add    %al,(%rax)
  4002f0:	47                   	rex.RXB
  4002f1:	4e 55                	rex.WRX push %rbp
  4002f3:	00 ac 0a 3f 45 39 4d 	add    %ch,0x4d39453f(%rdx,%rcx,1)
  4002fa:	f5                   	cmc    
  4002fb:	cb                   	lret   
  4002fc:	ab                   	stos   %eax,%es:(%rdi)
  4002fd:	2f                   	(bad)  
  4002fe:	3a 79 f1             	cmp    -0xf(%rcx),%bh
  400301:	2f                   	(bad)  
  400302:	37                   	(bad)  
  400303:	78 96                	js     40029b <printf@plt-0xd95>
  400305:	04 56                	add    $0x56,%al
  400307:	56                   	push   %rsi

Disassembly of section .gnu.hash:

0000000000400308 <.gnu.hash>:
  400308:	01 00                	add    %eax,(%rax)
  40030a:	00 00                	add    %al,(%rax)
  40030c:	01 00                	add    %eax,(%rax)
  40030e:	00 00                	add    %al,(%rax)
  400310:	01 00                	add    %eax,(%rax)
	...

Disassembly of section .dynsym:

0000000000400328 <.dynsym>:
	...
  400340:	0b 00                	or     (%rax),%eax
  400342:	00 00                	add    %al,(%rax)
  400344:	12 00                	adc    (%rax),%al
	...
  400356:	00 00                	add    %al,(%rax)
  400358:	12 00                	adc    (%rax),%al
  40035a:	00 00                	add    %al,(%rax)
  40035c:	12 00                	adc    (%rax),%al
	...
  40036e:	00 00                	add    %al,(%rax)
  400370:	30 00                	xor    %al,(%rax)
  400372:	00 00                	add    %al,(%rax)
  400374:	20 00                	and    %al,(%rax)
	...

Disassembly of section .dynstr:

0000000000400388 <.dynstr>:
  400388:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  40038c:	63 2e                	movslq (%rsi),%ebp
  40038e:	73 6f                	jae    4003ff <printf@plt-0xc31>
  400390:	2e 36 00 70 72       	cs add %dh,%ss:0x72(%rax)
  400395:	69 6e 74 66 00 5f 5f 	imul   $0x5f5f0066,0x74(%rsi),%ebp
  40039c:	6c                   	insb   (%dx),%es:(%rdi)
  40039d:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  4003a4:	72 74                	jb     40041a <printf@plt-0xc16>
  4003a6:	5f                   	pop    %rdi
  4003a7:	6d                   	insl   (%dx),%es:(%rdi)
  4003a8:	61                   	(bad)  
  4003a9:	69 6e 00 47 4c 49 42 	imul   $0x42494c47,0x0(%rsi),%ebp
  4003b0:	43 5f                	rex.XB pop %r15
  4003b2:	32 2e                	xor    (%rsi),%ch
  4003b4:	32 2e                	xor    (%rsi),%ch
  4003b6:	35 00 5f 5f 67       	xor    $0x675f5f00,%eax
  4003bb:	6d                   	insl   (%dx),%es:(%rdi)
  4003bc:	6f                   	outsl  %ds:(%rsi),(%dx)
  4003bd:	6e                   	outsb  %ds:(%rsi),(%dx)
  4003be:	5f                   	pop    %rdi
  4003bf:	73 74                	jae    400435 <printf@plt-0xbfb>
  4003c1:	61                   	(bad)  
  4003c2:	72 74                	jb     400438 <printf@plt-0xbf8>
  4003c4:	5f                   	pop    %rdi
  4003c5:	5f                   	pop    %rdi
	...

Disassembly of section .gnu.version:

00000000004003c8 <.gnu.version>:
  4003c8:	00 00                	add    %al,(%rax)
  4003ca:	02 00                	add    (%rax),%al
  4003cc:	02 00                	add    (%rax),%al
	...

Disassembly of section .gnu.version_r:

00000000004003d0 <.gnu.version_r>:
  4003d0:	01 00                	add    %eax,(%rax)
  4003d2:	01 00                	add    %eax,(%rax)
  4003d4:	01 00                	add    %eax,(%rax)
  4003d6:	00 00                	add    %al,(%rax)
  4003d8:	10 00                	adc    %al,(%rax)
  4003da:	00 00                	add    %al,(%rax)
  4003dc:	00 00                	add    %al,(%rax)
  4003de:	00 00                	add    %al,(%rax)
  4003e0:	75 1a                	jne    4003fc <printf@plt-0xc34>
  4003e2:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  4003e8:	24 00                	and    $0x0,%al
  4003ea:	00 00                	add    %al,(%rax)
  4003ec:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

00000000004003f0 <.rela.dyn>:
  4003f0:	f0 3f                	lock (bad) 
  4003f2:	40 00 00             	add    %al,(%rax)
  4003f5:	00 00                	add    %al,(%rax)
  4003f7:	00 06                	add    %al,(%rsi)
  4003f9:	00 00                	add    %al,(%rax)
  4003fb:	00 02                	add    %al,(%rdx)
	...
  400405:	00 00                	add    %al,(%rax)
  400407:	00 f8                	add    %bh,%al
  400409:	3f                   	(bad)  
  40040a:	40 00 00             	add    %al,(%rax)
  40040d:	00 00                	add    %al,(%rax)
  40040f:	00 06                	add    %al,(%rsi)
  400411:	00 00                	add    %al,(%rax)
  400413:	00 03                	add    %al,(%rbx)
	...

Disassembly of section .rela.plt:

0000000000400420 <.rela.plt>:
  400420:	18 40 40             	sbb    %al,0x40(%rax)
  400423:	00 00                	add    %al,(%rax)
  400425:	00 00                	add    %al,(%rax)
  400427:	00 07                	add    %al,(%rdi)
  400429:	00 00                	add    %al,(%rax)
  40042b:	00 01                	add    %al,(%rcx)
	...

Disassembly of section .init:

0000000000401000 <.init>:
  401000:	48 83 ec 08          	sub    $0x8,%rsp
  401004:	48 8b 05 ed 2f 00 00 	mov    0x2fed(%rip),%rax        # 403ff8 <printf@plt+0x2fc8>
  40100b:	48 85 c0             	test   %rax,%rax
  40100e:	74 02                	je     401012 <printf@plt-0x1e>
  401010:	ff d0                	callq  *%rax
  401012:	48 83 c4 08          	add    $0x8,%rsp
  401016:	c3                   	retq   

Disassembly of section .plt:

0000000000401020 <printf@plt-0x10>:
  401020:	ff 35 e2 2f 00 00    	pushq  0x2fe2(%rip)        # 404008 <printf@plt+0x2fd8>
  401026:	ff 25 e4 2f 00 00    	jmpq   *0x2fe4(%rip)        # 404010 <printf@plt+0x2fe0>
  40102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401030 <printf@plt>:
  401030:	ff 25 e2 2f 00 00    	jmpq   *0x2fe2(%rip)        # 404018 <printf@plt+0x2fe8>
  401036:	68 00 00 00 00       	pushq  $0x0
  40103b:	e9 e0 ff ff ff       	jmpq   401020 <printf@plt-0x10>

Disassembly of section .text:

0000000000401040 <.text>:
  401040:	31 ed                	xor    %ebp,%ebp
  401042:	49 89 d1             	mov    %rdx,%r9
  401045:	5e                   	pop    %rsi
  401046:	48 89 e2             	mov    %rsp,%rdx
  401049:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40104d:	50                   	push   %rax
  40104e:	54                   	push   %rsp
  40104f:	49 c7 c0 b0 11 40 00 	mov    $0x4011b0,%r8
  401056:	48 c7 c1 50 11 40 00 	mov    $0x401150,%rcx
  40105d:	48 c7 c7 22 11 40 00 	mov    $0x401122,%rdi
  401064:	ff 15 86 2f 00 00    	callq  *0x2f86(%rip)        # 403ff0 <printf@plt+0x2fc0>
  40106a:	f4                   	hlt    
  40106b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401070:	c3                   	retq   
  401071:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  401078:	00 00 00 
  40107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401080:	b8 30 40 40 00       	mov    $0x404030,%eax
  401085:	48 3d 30 40 40 00    	cmp    $0x404030,%rax
  40108b:	74 13                	je     4010a0 <printf@plt+0x70>
  40108d:	b8 00 00 00 00       	mov    $0x0,%eax
  401092:	48 85 c0             	test   %rax,%rax
  401095:	74 09                	je     4010a0 <printf@plt+0x70>
  401097:	bf 30 40 40 00       	mov    $0x404030,%edi
  40109c:	ff e0                	jmpq   *%rax
  40109e:	66 90                	xchg   %ax,%ax
  4010a0:	c3                   	retq   
  4010a1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4010a8:	00 00 00 00 
  4010ac:	0f 1f 40 00          	nopl   0x0(%rax)
  4010b0:	be 30 40 40 00       	mov    $0x404030,%esi
  4010b5:	48 81 ee 30 40 40 00 	sub    $0x404030,%rsi
  4010bc:	48 c1 fe 03          	sar    $0x3,%rsi
  4010c0:	48 89 f0             	mov    %rsi,%rax
  4010c3:	48 c1 e8 3f          	shr    $0x3f,%rax
  4010c7:	48 01 c6             	add    %rax,%rsi
  4010ca:	48 d1 fe             	sar    %rsi
  4010cd:	74 11                	je     4010e0 <printf@plt+0xb0>
  4010cf:	b8 00 00 00 00       	mov    $0x0,%eax
  4010d4:	48 85 c0             	test   %rax,%rax
  4010d7:	74 07                	je     4010e0 <printf@plt+0xb0>
  4010d9:	bf 30 40 40 00       	mov    $0x404030,%edi
  4010de:	ff e0                	jmpq   *%rax
  4010e0:	c3                   	retq   
  4010e1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4010e8:	00 00 00 00 
  4010ec:	0f 1f 40 00          	nopl   0x0(%rax)
  4010f0:	80 3d 39 2f 00 00 00 	cmpb   $0x0,0x2f39(%rip)        # 404030 <printf@plt+0x3000>
  4010f7:	75 17                	jne    401110 <printf@plt+0xe0>
  4010f9:	55                   	push   %rbp
  4010fa:	48 89 e5             	mov    %rsp,%rbp
  4010fd:	e8 7e ff ff ff       	callq  401080 <printf@plt+0x50>
  401102:	c6 05 27 2f 00 00 01 	movb   $0x1,0x2f27(%rip)        # 404030 <printf@plt+0x3000>
  401109:	5d                   	pop    %rbp
  40110a:	c3                   	retq   
  40110b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401110:	c3                   	retq   
  401111:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401118:	00 00 00 00 
  40111c:	0f 1f 40 00          	nopl   0x0(%rax)
  401120:	eb 8e                	jmp    4010b0 <printf@plt+0x80>
  401122:	55                   	push   %rbp
  401123:	48 89 e5             	mov    %rsp,%rbp
  401126:	48 83 ec 10          	sub    $0x10,%rsp
  40112a:	c7 45 fc 64 00 00 00 	movl   $0x64,-0x4(%rbp)
  401131:	8b 45 fc             	mov    -0x4(%rbp),%eax
  401134:	89 c6                	mov    %eax,%esi
  401136:	bf 04 20 40 00       	mov    $0x402004,%edi
  40113b:	b8 00 00 00 00       	mov    $0x0,%eax
  401140:	e8 eb fe ff ff       	callq  401030 <printf@plt>
  401145:	b8 00 00 00 00       	mov    $0x0,%eax
  40114a:	c9                   	leaveq 
  40114b:	c3                   	retq   
  40114c:	0f 1f 40 00          	nopl   0x0(%rax)
  401150:	41 57                	push   %r15
  401152:	49 89 d7             	mov    %rdx,%r15
  401155:	41 56                	push   %r14
  401157:	49 89 f6             	mov    %rsi,%r14
  40115a:	41 55                	push   %r13
  40115c:	41 89 fd             	mov    %edi,%r13d
  40115f:	41 54                	push   %r12
  401161:	4c 8d 25 a8 2c 00 00 	lea    0x2ca8(%rip),%r12        # 403e10 <printf@plt+0x2de0>
  401168:	55                   	push   %rbp
  401169:	48 8d 2d a8 2c 00 00 	lea    0x2ca8(%rip),%rbp        # 403e18 <printf@plt+0x2de8>
  401170:	53                   	push   %rbx
  401171:	4c 29 e5             	sub    %r12,%rbp
  401174:	48 83 ec 08          	sub    $0x8,%rsp
  401178:	e8 83 fe ff ff       	callq  401000 <printf@plt-0x30>
  40117d:	48 c1 fd 03          	sar    $0x3,%rbp
  401181:	74 1b                	je     40119e <printf@plt+0x16e>
  401183:	31 db                	xor    %ebx,%ebx
  401185:	0f 1f 00             	nopl   (%rax)
  401188:	4c 89 fa             	mov    %r15,%rdx
  40118b:	4c 89 f6             	mov    %r14,%rsi
  40118e:	44 89 ef             	mov    %r13d,%edi
  401191:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  401195:	48 83 c3 01          	add    $0x1,%rbx
  401199:	48 39 dd             	cmp    %rbx,%rbp
  40119c:	75 ea                	jne    401188 <printf@plt+0x158>
  40119e:	48 83 c4 08          	add    $0x8,%rsp
  4011a2:	5b                   	pop    %rbx
  4011a3:	5d                   	pop    %rbp
  4011a4:	41 5c                	pop    %r12
  4011a6:	41 5d                	pop    %r13
  4011a8:	41 5e                	pop    %r14
  4011aa:	41 5f                	pop    %r15
  4011ac:	c3                   	retq   
  4011ad:	0f 1f 00             	nopl   (%rax)
  4011b0:	c3                   	retq   

Disassembly of section .fini:

00000000004011b4 <.fini>:
  4011b4:	48 83 ec 08          	sub    $0x8,%rsp
  4011b8:	48 83 c4 08          	add    $0x8,%rsp
  4011bc:	c3                   	retq   

Disassembly of section .rodata:

0000000000402000 <.rodata>:
  402000:	01 00                	add    %eax,(%rax)
  402002:	02 00                	add    (%rax),%al
  402004:	48                   	rex.W
  402005:	65 6c                	gs insb (%dx),%es:(%rdi)
  402007:	6c                   	insb   (%dx),%es:(%rdi)
  402008:	6f                   	outsl  %ds:(%rsi),(%dx)
  402009:	20                   	.byte 0x20
  40200a:	25                   	.byte 0x25
  40200b:	64 0a 00             	or     %fs:(%rax),%al

Disassembly of section .eh_frame_hdr:

0000000000402010 <.eh_frame_hdr>:
  402010:	01 1b                	add    %ebx,(%rbx)
  402012:	03 3b                	add    (%rbx),%edi
  402014:	3c 00                	cmp    $0x0,%al
  402016:	00 00                	add    %al,(%rax)
  402018:	06                   	(bad)  
  402019:	00 00                	add    %al,(%rax)
  40201b:	00 10                	add    %dl,(%rax)
  40201d:	f0 ff                	lock (bad) 
  40201f:	ff 98 00 00 00 30    	lcall  *0x30000000(%rax)
  402025:	f0 ff                	lock (bad) 
  402027:	ff 58 00             	lcall  *0x0(%rax)
  40202a:	00 00                	add    %al,(%rax)
  40202c:	60                   	(bad)  
  40202d:	f0 ff                	lock (bad) 
  40202f:	ff 84 00 00 00 12 f1 	incl   -0xeee0000(%rax,%rax,1)
  402036:	ff                   	(bad)  
  402037:	ff c0                	inc    %eax
  402039:	00 00                	add    %al,(%rax)
  40203b:	00 40 f1             	add    %al,-0xf(%rax)
  40203e:	ff                   	(bad)  
  40203f:	ff e0                	jmpq   *%rax
  402041:	00 00                	add    %al,(%rax)
  402043:	00 a0 f1 ff ff 28    	add    %ah,0x28fffff1(%rax)
  402049:	01 00                	add    %eax,(%rax)
	...

Disassembly of section .eh_frame:

0000000000402050 <.eh_frame>:
  402050:	14 00                	adc    $0x0,%al
  402052:	00 00                	add    %al,(%rax)
  402054:	00 00                	add    %al,(%rax)
  402056:	00 00                	add    %al,(%rax)
  402058:	01 7a 52             	add    %edi,0x52(%rdx)
  40205b:	00 01                	add    %al,(%rcx)
  40205d:	78 10                	js     40206f <printf@plt+0x103f>
  40205f:	01 1b                	add    %ebx,(%rbx)
  402061:	0c 07                	or     $0x7,%al
  402063:	08 90 01 07 10 10    	or     %dl,0x10100701(%rax)
  402069:	00 00                	add    %al,(%rax)
  40206b:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40206e:	00 00                	add    %al,(%rax)
  402070:	d0 ef                	shr    %bh
  402072:	ff                   	(bad)  
  402073:	ff 2b                	ljmp   *(%rbx)
  402075:	00 00                	add    %al,(%rax)
  402077:	00 00                	add    %al,(%rax)
  402079:	00 00                	add    %al,(%rax)
  40207b:	00 14 00             	add    %dl,(%rax,%rax,1)
  40207e:	00 00                	add    %al,(%rax)
  402080:	00 00                	add    %al,(%rax)
  402082:	00 00                	add    %al,(%rax)
  402084:	01 7a 52             	add    %edi,0x52(%rdx)
  402087:	00 01                	add    %al,(%rcx)
  402089:	78 10                	js     40209b <printf@plt+0x106b>
  40208b:	01 1b                	add    %ebx,(%rbx)
  40208d:	0c 07                	or     $0x7,%al
  40208f:	08 90 01 00 00 10    	or     %dl,0x10000001(%rax)
  402095:	00 00                	add    %al,(%rax)
  402097:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40209a:	00 00                	add    %al,(%rax)
  40209c:	d4                   	(bad)  
  40209d:	ef                   	out    %eax,(%dx)
  40209e:	ff                   	(bad)  
  40209f:	ff 01                	incl   (%rcx)
  4020a1:	00 00                	add    %al,(%rax)
  4020a3:	00 00                	add    %al,(%rax)
  4020a5:	00 00                	add    %al,(%rax)
  4020a7:	00 24 00             	add    %ah,(%rax,%rax,1)
  4020aa:	00 00                	add    %al,(%rax)
  4020ac:	30 00                	xor    %al,(%rax)
  4020ae:	00 00                	add    %al,(%rax)
  4020b0:	70 ef                	jo     4020a1 <printf@plt+0x1071>
  4020b2:	ff                   	(bad)  
  4020b3:	ff 20                	jmpq   *(%rax)
  4020b5:	00 00                	add    %al,(%rax)
  4020b7:	00 00                	add    %al,(%rax)
  4020b9:	0e                   	(bad)  
  4020ba:	10 46 0e             	adc    %al,0xe(%rsi)
  4020bd:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  4020c0:	0b 77 08             	or     0x8(%rdi),%esi
  4020c3:	80 00 3f             	addb   $0x3f,(%rax)
  4020c6:	1a 3b                	sbb    (%rbx),%bh
  4020c8:	2a 33                	sub    (%rbx),%dh
  4020ca:	24 22                	and    $0x22,%al
  4020cc:	00 00                	add    %al,(%rax)
  4020ce:	00 00                	add    %al,(%rax)
  4020d0:	1c 00                	sbb    $0x0,%al
  4020d2:	00 00                	add    %al,(%rax)
  4020d4:	58                   	pop    %rax
  4020d5:	00 00                	add    %al,(%rax)
  4020d7:	00 4a f0             	add    %cl,-0x10(%rdx)
  4020da:	ff                   	(bad)  
  4020db:	ff 2a                	ljmp   *(%rdx)
  4020dd:	00 00                	add    %al,(%rax)
  4020df:	00 00                	add    %al,(%rax)
  4020e1:	41 0e                	rex.B (bad) 
  4020e3:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4020e9:	65 0c 07             	gs or  $0x7,%al
  4020ec:	08 00                	or     %al,(%rax)
  4020ee:	00 00                	add    %al,(%rax)
  4020f0:	44 00 00             	add    %r8b,(%rax)
  4020f3:	00 78 00             	add    %bh,0x0(%rax)
  4020f6:	00 00                	add    %al,(%rax)
  4020f8:	58                   	pop    %rax
  4020f9:	f0 ff                	lock (bad) 
  4020fb:	ff 5d 00             	lcall  *0x0(%rbp)
  4020fe:	00 00                	add    %al,(%rax)
  402100:	00 42 0e             	add    %al,0xe(%rdx)
  402103:	10 8f 02 45 0e 18    	adc    %cl,0x180e4502(%rdi)
  402109:	8e 03                	mov    (%rbx),%es
  40210b:	45 0e                	rex.RB (bad) 
  40210d:	20 8d 04 45 0e 28    	and    %cl,0x280e4504(%rbp)
  402113:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86702f61 <printf@plt+0xffffffff86301f31>
  402119:	06                   	(bad)  
  40211a:	48 0e                	rex.W (bad) 
  40211c:	38 83 07 47 0e 40    	cmp    %al,0x400e4707(%rbx)
  402122:	6a 0e                	pushq  $0xe
  402124:	38 41 0e             	cmp    %al,0xe(%rcx)
  402127:	30 41 0e             	xor    %al,0xe(%rcx)
  40212a:	28 42 0e             	sub    %al,0xe(%rdx)
  40212d:	20 42 0e             	and    %al,0xe(%rdx)
  402130:	18 42 0e             	sbb    %al,0xe(%rdx)
  402133:	10 42 0e             	adc    %al,0xe(%rdx)
  402136:	08 00                	or     %al,(%rax)
  402138:	10 00                	adc    %al,(%rax)
  40213a:	00 00                	add    %al,(%rax)
  40213c:	c0 00 00             	rolb   $0x0,(%rax)
  40213f:	00 70 f0             	add    %dh,-0x10(%rax)
  402142:	ff                   	(bad)  
  402143:	ff 01                	incl   (%rcx)
	...

Disassembly of section .init_array:

0000000000403e10 <.init_array>:
  403e10:	20 11                	and    %dl,(%rcx)
  403e12:	40 00 00             	add    %al,(%rax)
  403e15:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000403e18 <.fini_array>:
  403e18:	f0 10 40 00          	lock adc %al,0x0(%rax)
  403e1c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .dynamic:

0000000000403e20 <.dynamic>:
  403e20:	01 00                	add    %eax,(%rax)
  403e22:	00 00                	add    %al,(%rax)
  403e24:	00 00                	add    %al,(%rax)
  403e26:	00 00                	add    %al,(%rax)
  403e28:	01 00                	add    %eax,(%rax)
  403e2a:	00 00                	add    %al,(%rax)
  403e2c:	00 00                	add    %al,(%rax)
  403e2e:	00 00                	add    %al,(%rax)
  403e30:	0c 00                	or     $0x0,%al
  403e32:	00 00                	add    %al,(%rax)
  403e34:	00 00                	add    %al,(%rax)
  403e36:	00 00                	add    %al,(%rax)
  403e38:	00 10                	add    %dl,(%rax)
  403e3a:	40 00 00             	add    %al,(%rax)
  403e3d:	00 00                	add    %al,(%rax)
  403e3f:	00 0d 00 00 00 00    	add    %cl,0x0(%rip)        # 403e45 <printf@plt+0x2e15>
  403e45:	00 00                	add    %al,(%rax)
  403e47:	00 b4 11 40 00 00 00 	add    %dh,0x40(%rcx,%rdx,1)
  403e4e:	00 00                	add    %al,(%rax)
  403e50:	19 00                	sbb    %eax,(%rax)
  403e52:	00 00                	add    %al,(%rax)
  403e54:	00 00                	add    %al,(%rax)
  403e56:	00 00                	add    %al,(%rax)
  403e58:	10 3e                	adc    %bh,(%rsi)
  403e5a:	40 00 00             	add    %al,(%rax)
  403e5d:	00 00                	add    %al,(%rax)
  403e5f:	00 1b                	add    %bl,(%rbx)
  403e61:	00 00                	add    %al,(%rax)
  403e63:	00 00                	add    %al,(%rax)
  403e65:	00 00                	add    %al,(%rax)
  403e67:	00 08                	add    %cl,(%rax)
  403e69:	00 00                	add    %al,(%rax)
  403e6b:	00 00                	add    %al,(%rax)
  403e6d:	00 00                	add    %al,(%rax)
  403e6f:	00 1a                	add    %bl,(%rdx)
  403e71:	00 00                	add    %al,(%rax)
  403e73:	00 00                	add    %al,(%rax)
  403e75:	00 00                	add    %al,(%rax)
  403e77:	00 18                	add    %bl,(%rax)
  403e79:	3e 40 00 00          	add    %al,%ds:(%rax)
  403e7d:	00 00                	add    %al,(%rax)
  403e7f:	00 1c 00             	add    %bl,(%rax,%rax,1)
  403e82:	00 00                	add    %al,(%rax)
  403e84:	00 00                	add    %al,(%rax)
  403e86:	00 00                	add    %al,(%rax)
  403e88:	08 00                	or     %al,(%rax)
  403e8a:	00 00                	add    %al,(%rax)
  403e8c:	00 00                	add    %al,(%rax)
  403e8e:	00 00                	add    %al,(%rax)
  403e90:	f5                   	cmc    
  403e91:	fe                   	(bad)  
  403e92:	ff 6f 00             	ljmp   *0x0(%rdi)
  403e95:	00 00                	add    %al,(%rax)
  403e97:	00 08                	add    %cl,(%rax)
  403e99:	03 40 00             	add    0x0(%rax),%eax
  403e9c:	00 00                	add    %al,(%rax)
  403e9e:	00 00                	add    %al,(%rax)
  403ea0:	05 00 00 00 00       	add    $0x0,%eax
  403ea5:	00 00                	add    %al,(%rax)
  403ea7:	00 88 03 40 00 00    	add    %cl,0x4003(%rax)
  403ead:	00 00                	add    %al,(%rax)
  403eaf:	00 06                	add    %al,(%rsi)
  403eb1:	00 00                	add    %al,(%rax)
  403eb3:	00 00                	add    %al,(%rax)
  403eb5:	00 00                	add    %al,(%rax)
  403eb7:	00 28                	add    %ch,(%rax)
  403eb9:	03 40 00             	add    0x0(%rax),%eax
  403ebc:	00 00                	add    %al,(%rax)
  403ebe:	00 00                	add    %al,(%rax)
  403ec0:	0a 00                	or     (%rax),%al
  403ec2:	00 00                	add    %al,(%rax)
  403ec4:	00 00                	add    %al,(%rax)
  403ec6:	00 00                	add    %al,(%rax)
  403ec8:	3f                   	(bad)  
  403ec9:	00 00                	add    %al,(%rax)
  403ecb:	00 00                	add    %al,(%rax)
  403ecd:	00 00                	add    %al,(%rax)
  403ecf:	00 0b                	add    %cl,(%rbx)
  403ed1:	00 00                	add    %al,(%rax)
  403ed3:	00 00                	add    %al,(%rax)
  403ed5:	00 00                	add    %al,(%rax)
  403ed7:	00 18                	add    %bl,(%rax)
  403ed9:	00 00                	add    %al,(%rax)
  403edb:	00 00                	add    %al,(%rax)
  403edd:	00 00                	add    %al,(%rax)
  403edf:	00 15 00 00 00 00    	add    %dl,0x0(%rip)        # 403ee5 <printf@plt+0x2eb5>
	...
  403eed:	00 00                	add    %al,(%rax)
  403eef:	00 03                	add    %al,(%rbx)
	...
  403ef9:	40                   	rex
  403efa:	40 00 00             	add    %al,(%rax)
  403efd:	00 00                	add    %al,(%rax)
  403eff:	00 02                	add    %al,(%rdx)
  403f01:	00 00                	add    %al,(%rax)
  403f03:	00 00                	add    %al,(%rax)
  403f05:	00 00                	add    %al,(%rax)
  403f07:	00 18                	add    %bl,(%rax)
  403f09:	00 00                	add    %al,(%rax)
  403f0b:	00 00                	add    %al,(%rax)
  403f0d:	00 00                	add    %al,(%rax)
  403f0f:	00 14 00             	add    %dl,(%rax,%rax,1)
  403f12:	00 00                	add    %al,(%rax)
  403f14:	00 00                	add    %al,(%rax)
  403f16:	00 00                	add    %al,(%rax)
  403f18:	07                   	(bad)  
  403f19:	00 00                	add    %al,(%rax)
  403f1b:	00 00                	add    %al,(%rax)
  403f1d:	00 00                	add    %al,(%rax)
  403f1f:	00 17                	add    %dl,(%rdi)
  403f21:	00 00                	add    %al,(%rax)
  403f23:	00 00                	add    %al,(%rax)
  403f25:	00 00                	add    %al,(%rax)
  403f27:	00 20                	add    %ah,(%rax)
  403f29:	04 40                	add    $0x40,%al
  403f2b:	00 00                	add    %al,(%rax)
  403f2d:	00 00                	add    %al,(%rax)
  403f2f:	00 07                	add    %al,(%rdi)
  403f31:	00 00                	add    %al,(%rax)
  403f33:	00 00                	add    %al,(%rax)
  403f35:	00 00                	add    %al,(%rax)
  403f37:	00 f0                	add    %dh,%al
  403f39:	03 40 00             	add    0x0(%rax),%eax
  403f3c:	00 00                	add    %al,(%rax)
  403f3e:	00 00                	add    %al,(%rax)
  403f40:	08 00                	or     %al,(%rax)
  403f42:	00 00                	add    %al,(%rax)
  403f44:	00 00                	add    %al,(%rax)
  403f46:	00 00                	add    %al,(%rax)
  403f48:	30 00                	xor    %al,(%rax)
  403f4a:	00 00                	add    %al,(%rax)
  403f4c:	00 00                	add    %al,(%rax)
  403f4e:	00 00                	add    %al,(%rax)
  403f50:	09 00                	or     %eax,(%rax)
  403f52:	00 00                	add    %al,(%rax)
  403f54:	00 00                	add    %al,(%rax)
  403f56:	00 00                	add    %al,(%rax)
  403f58:	18 00                	sbb    %al,(%rax)
  403f5a:	00 00                	add    %al,(%rax)
  403f5c:	00 00                	add    %al,(%rax)
  403f5e:	00 00                	add    %al,(%rax)
  403f60:	fe                   	(bad)  
  403f61:	ff                   	(bad)  
  403f62:	ff 6f 00             	ljmp   *0x0(%rdi)
  403f65:	00 00                	add    %al,(%rax)
  403f67:	00 d0                	add    %dl,%al
  403f69:	03 40 00             	add    0x0(%rax),%eax
  403f6c:	00 00                	add    %al,(%rax)
  403f6e:	00 00                	add    %al,(%rax)
  403f70:	ff                   	(bad)  
  403f71:	ff                   	(bad)  
  403f72:	ff 6f 00             	ljmp   *0x0(%rdi)
  403f75:	00 00                	add    %al,(%rax)
  403f77:	00 01                	add    %al,(%rcx)
  403f79:	00 00                	add    %al,(%rax)
  403f7b:	00 00                	add    %al,(%rax)
  403f7d:	00 00                	add    %al,(%rax)
  403f7f:	00 f0                	add    %dh,%al
  403f81:	ff                   	(bad)  
  403f82:	ff 6f 00             	ljmp   *0x0(%rdi)
  403f85:	00 00                	add    %al,(%rax)
  403f87:	00 c8                	add    %cl,%al
  403f89:	03 40 00             	add    0x0(%rax),%eax
	...

Disassembly of section .got:

0000000000403ff0 <.got>:
	...

Disassembly of section .got.plt:

0000000000404000 <.got.plt>:
  404000:	20 3e                	and    %bh,(%rsi)
  404002:	40 00 00             	add    %al,(%rax)
	...
  404015:	00 00                	add    %al,(%rax)
  404017:	00 36                	add    %dh,(%rsi)
  404019:	10 40 00             	adc    %al,0x0(%rax)
  40401c:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000404020 <.data>:
	...

Disassembly of section .bss:

0000000000404030 <.bss>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 6f             	sub    %dl,0x6f(%rbp)
   8:	73 20                	jae    2a <printf@plt-0x401006>
   a:	38 2e                	cmp    %ch,(%rsi)
   c:	33 2e                	xor    (%rsi),%ebp
   e:	30 2e                	xor    %ch,(%rsi)
  10:	33 2d 33 2b 72 65    	xor    0x65722b33(%rip),%ebp        # 65722b49 <printf@plt+0x65321b19>
  16:	62                   	(bad)  
  17:	75 69                	jne    82 <printf@plt-0x400fae>
  19:	6c                   	insb   (%dx),%es:(%rdi)
  1a:	64 29 20             	sub    %esp,%fs:(%rax)
  1d:	38 2e                	cmp    %ch,(%rsi)
  1f:	33 2e                	xor    (%rsi),%ebp
  21:	30 00                	xor    %al,(%rax)
