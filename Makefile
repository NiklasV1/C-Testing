tokenFunction: tokenFunction.c
	@gcc tokenFunction.c -o tokenFunctionExec -O3 -static
	@./tokenFunctionExec

