# Disciplina: Arquitetura e Organização de Processadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 03
# Alunos: Cauã Domingos e Taryck Gean Santos Pego

.data # segmento de dados

	newline: .asciz "\n"
	Msg1: .asciz "\n\n Entre com o tamanho do Vetor_Aor (máx. = 8): "
	Msg2: .asciz "\n\n Valor inválido! "
	Msg3: .asciz "\n\n Vetor_A["
	Msg4: .asciz "]: "
	Msg5: .asciz "\n\n Digite o índice do valor a ser impresso: " 
	Msg6: .asciz "\n\n O elemento do vetor na posição: "
	Msg7: .asciz " possui o valor "
	buffer: .asciz ""
	Vetor_A: .word 0, 0, 0, 0, 0, 0, 0, 0
	
.text # segmento de código

main:

	li t0, 0 # Declarando t0 = 0
	li t1, 0 # Declarando t1 = 0
	li t3, 0 # Declarando t0 = 0
	li t4, 1 # Declarando t0 = 0
	li s7, 0 # Declarando s7 = 0
	la s0, Vetor_A

	# Print na mensagem 1
	li a7, 4 # Chama o serviço 4 (print_string)
	la a0, Msg1 # Msg1
	ecall
		
	# Lê a variável
	li a7, 5 # Chama o serviço 5 (read_int)
	ecall
		
	# Move o inteiro para o endereço t1
	mv s7, a0
	
	slti t3, s7, 9
	bne t3, t4, mensagem_invalida
		
	loop_inserir_vetor:
			
		# Print na mensagem 1
		li a7, 4 # Chama o serviço 4 (print_string)
		la a0, Msg3 # Msg1
		ecall
		
		# Print na constante $t0
		li a7, 1 # Chama o serviço 1 (print_int)
		mv a0, t0 # Carrega a constante de $t0 para o syscall
		ecall
		
		# Print na mensagem 2
		li a7, 4 # Chama o serviço 4 (print_string)
		la a0, Msg4 # Msg2
		ecall
		
		# Lê a variável
		li a7, 5 # Chama o serviço 5 (read_int)
		ecall
		
		# Move o inteiro para o endereço t1
		mv t1, a0
		
		sw t1, Vetor_A(s0) # Coloca na posição $s0 o valor contido em $t1
		
		addi t0, t0, 1 # adiciona 1 em t0
		addi s0, s0, 4 # adiciona 4 (1 word) em s0
		bne t0, s7, loop_inserir_vetor # Caso $t0 seja diferente de $s7 retorna ao loop
		
		li t0, 1 # adiciona 1 em t0
		li t1, 1 # adiciona 1 em t0
		li s1, 1 # adiciona 1 em t0
		li s0, 4 # adiciona 4 (1 word) em s0
		
		# Print na mensagem 1
		li a7, 4 # Chama o serviço 4 (print_string)
		la a0, Msg5 # Msg1
		ecall
		
		# Lê a variável
		li a7, 5 # Chama o serviço 5 (read_int)
		ecall
		
		# Move o inteiro para o endereço t1
		mv s1, a7
		#j loop_buscar_vetor
		
	mensagem_invalida: 
		
		# Print na mensagem 1
		li a7, 4 # Chama o serviço 4 (print_string)
		la a0, Msg2 # Msg1
		ecall	
		
		j main
		
	#loop_buscar_vetor:
		
		#beq $t1, $t0, $s7
		#addi $t0, 1
	#	bne $t1, $zero, loop_buscar_vetor
		
	#	O elemento do vetor na posição
