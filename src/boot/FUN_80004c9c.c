/* FUN_80004c9c
 * image   boot (boot), base 0x80000480
 * address 0x80004c9c  body 0x80004c9c..0x80004cfb  size 96 B
 * body sha256 dd4e9e5812f0d7ee2a57a982d376cdbbe5c4c23554942b3f27257ec1d057dfde
 * provider record sha256 9778b668d0fe3fc09690894474cd79713416930ef010738eaad65f934ae705c7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80004c9c(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  undefined1 auStack_10 [4];
  undefined4 local_c;
  
  piVar2 = (int *)(param_1 * 8 + _DAT_80012874);
  uVar3 = piVar2[1];
  uVar1 = 0;
  if (uVar3 != 0) {
    if ((uVar3 & 1) != 0) {
      uVar3 = uVar3 + 1;
    }
    func_0x800888ec(_DAT_800128a8 + *piVar2 + uVar3,auStack_10,8);
    uVar1 = local_c;
  }
  return uVar1;
}
