# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 03 – Programação em Linguagem de Montagem
# Aluno: Caua Domingos e Taryck Santos

.data #Segmento de Dados

	Msg1: .asciz "\n\n Digite um valor para X: "
	Msg2: .asciz "\n\n Digite um valor para Y: "
	Msg3: .asciz "\n\n Resultado do MDC: "
	
.text #Segmento de Texto

global:

	j main
	
mdc:

	addi sp, sp, -4 #Aloca espaço na pilha
	sw ra, 4(sp) #Salva o endereço de retorno na pilha
	sw s1, 0(sp) #Salva o registrador s1 na pilha
	
	while:
	
		beq s1, s2, end_while
		blt s1, s2, if_lt
		
		sub s1, s1, s2
		j while
		
	if_lt:
	
		sub s2, s2, s1
		j while
		
	end_while:
	
		mv s7, s1
		lw ra, 4(sp)
		lw s0, 0(sp)      
        addi sp, sp, 4        
        jr ra               

main:

	#Armazenando um valor para X
	li a7, 4 # Chama o serviço 4 (print_string)
	la a0, Msg1 # Msg1
	ecall
	
	li a7, 5 # Chama o serviço 5 (read_int)
	ecall
	
	mv s1, a0 # Move o inteiro para o endereço s1
	
	#Armazenando um valor para Y
	li a7, 4 # Chama o serviço 4 (print_string)
	la a0, Msg2 # Msg2
	ecall
	
	li a7, 5 # Chama o serviço 5 (read_int)
	ecall
	
	mv s2, a0 # Move o inteiro para o endereço s2
	
	jal mdc
	
	#Mostra a Msg3
	li a7, 4 
	la a0, Msg3 
	ecall
	
	# Print na constante s0
	li a7, 1
	mv a0, s7 
	ecall
