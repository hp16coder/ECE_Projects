ORG 4000H
mov p2,#00h
mov r2,#10
mov dptr,#0200h
up:clr a
movc a,@a+dptr
mov p2,a 
acall delay 
inc dptr 
djnz r2,up
sjmp repeat 
delay:mov r4,#15
L3: mov r5,#255
L2: mov r6,#255
L1: djnz r6,L1 
     djnz r5,L2 
	 djnz r4,L3
	 ret 
	 org 0200h
		 db