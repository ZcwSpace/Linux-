.section.text
.extern KernelMain
.global loader
loade:
    mov %kernel_stack, %esp
    