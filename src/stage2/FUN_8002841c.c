/* FUN_8002841c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002841c  body 0x8002841c..0x80028447  size 44 B
 * body sha256 aa5c328c75bc80e0870c9477ed4d73a8e7f6b4f6e83c57d593b6abd41858a57f
 * provider record sha256 926fabcb041b2bd1ba72f3e1df95aa79861a7bbf59b0e31db99b451cebb52181
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002841c(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x118);
  *(undefined4 *)(iVar1 + 0x114) = 0;
  return;
}
