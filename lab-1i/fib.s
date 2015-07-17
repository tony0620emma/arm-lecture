	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func

	.global fibonacci
	.type fibonacci, function

fibonacci:
	@ ADD/MODIFY CODE BELOW
	@ PROLOG
	push {r3, r4, r5, lr}

	@ pre=r3 , result=r5

	subs r4, r0, #0
	ble .L_return_0

	cmp r0, #1
	beq .L_return_1
	
	mov r3, #0     	@ previous = 0
	add r4, r3, #1 	@ result   = 1
	bl .L_for_loop

.L_for_loop:
	add r5, r3, r4 	@ sum    = pre + result
	mov r3, r4      @ pre    = result
	mov r4, r5 	@ result = sum
	sub r0, r0, #1
	cmp r0, #2
	ble .L_result
	bl .L_for_loop

.L_return_0:
	mov r0, #0
	pop {r3, r4, r5, pc}
.L_return_1:
	mov r0, #1
	pop {r3, r4, r5, pc}
.L_result:
	mov r0, r4
	pop {r3, r4, r5, pc}

	@EPILOG

	

	.size fibonacci, .-fibonacci
	.end
