import java.util.*;
public final class Visitor
{
	public static void Visit(Node base)
	{ 
		
		StatementsNode t = (StatementsNode)base;
		//System.out.println(t.children.size());
		// We send the queue to our walker method that will walk through each child of the statement node
		recursiveWalk(t.children,0,1,t.children.size());
		
	}
	//each recursive call we move onto the next children in the queue
	// So to do this we need to keep track of the queue itself, the instruction number line count, track of what children we are on, the total number of children
	private static int recursiveWalk(Queue<Node> b, int intN,int c, int size)
	{
		//recursive call ends when we have gone through all of the children of the Statement Node
		if(c>size)
			return intN++;
		char type = b.peek().GetType(); // Getting the type of the current child to see if it is TwoOperand or While Node
		
		if(type == 's')
		{
			StatementsNode t = (StatementsNode)b.remove();
			intN = recursiveWalk(t.children,intN++,1,t.children.size());
		}
		
		if(type=='-'|| type=='+'|| type=='*'||type=='/')
		{
			TwoOperandNode t2=(TwoOperandNode)b.remove(); // We store the Node as a TwoOperand Node and also remove it from the queue
			//we print the appropriate tag for the line depending on the type for this current TwoOperand Node
			if(type=='+')
				System.out.print(intN+": add ");
			if(type=='-')
				System.out.print(intN+": sub ");
			if(type=='*')
				System.out.print(intN+": mul ");
			if(type=='/')
				System.out.print(intN+": div ");
			//We check to see what is the type of the first operand, if the type is A then that means we have
			// an address operand meaning that we put $ in front
			// however if the type is R then that means it is a register operand so we put R in front of the operand
			// We repeat this for both operands since both operands dont have to be of same type
			if(t2.operand1.GetType()=='A')
			{
				AddressOperand op = (AddressOperand)t2.operand1;
				System.out.print('$');
				System.out.print(op.GetAddress()+",");
				
			}
			else
			{
				RegisterOperand op = (RegisterOperand)t2.operand1;
				System.out.print('R');
				System.out.print(op.GetRegister()+",");
				
			}
			if(t2.operand2.GetType()=='A')
			{
				
				AddressOperand op2 = (AddressOperand)t2.operand2;
				System.out.print('$');
				System.out.println(op2.GetAddress());
			}
			else
			{
				RegisterOperand op2 = (RegisterOperand)t2.operand2;
				System.out.print('R');
				System.out.println(op2.GetRegister());
				
			}
			//when we reach here we then move onto the next child
			return recursiveWalk(b,++intN,++c,size);
		}
		if(type=='w')
		{
			//The current node is while Node so we need to walk through each statement and conditions
			// And to do this we need to have two recursive calls, one to go through each condition and
			// one to go through each statement
			WhileNode wTemp = (WhileNode)b.peek();
			int csize=0,ssize=0;
			csize=wTemp.conditions.children.size(); //stores the number of children we need to walk through for the conditions
			ssize=wTemp.statements.children.size();//stores the number of children we nee to walk though for the statements
			int startW=intN;
			int temp = intN;//holds what the instruction number is prior to going through the while node so that we know where the jmp should go to
			int counter=1;
			//we walk through all the conditions first and we also return the value for what line number we should be at
			startW=recursiveWalk(wTemp.conditions.children,intN++,counter,csize);
			System.out.println(startW+": bne $00000000");
			//similar to how we do the conditions, but we update our second parameter with the new line number, and the size is based off number of statement nodes
			startW=recursiveWalk(wTemp.statements.children,++startW,counter,ssize);
			
			System.out.println(startW+": jmp $"+temp);
			//we finished going through the whileNode so we can now remove it from the queue and move onto the next children
			b.poll();
			
			return recursiveWalk(b,++startW,++c,size);
			
		}
		//System.out.println("je");
		//if we hit this then we are finished going over children of nested Statement node and are now moving onto the next child
		return recursiveWalk(b,intN++,++c,size);
		
	}
	
	
}