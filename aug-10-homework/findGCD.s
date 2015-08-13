	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func
	
	.global findGCD_arm_v1
	.type findGCD_arm_v1, function

	.global findGCD_arm_v2
	.type findGCD_arm_v2, function

	.global findGCD_arm_v3
	.type findGCD_arm_v3, function

findGCD_arm_v1:
	push {r3, r4, r5, r6, lr}
	
	
	
	pop {r3, r4, r5, r6, lr}
