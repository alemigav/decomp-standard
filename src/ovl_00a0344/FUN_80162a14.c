/* FUN_80162a14
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162a14  body 0x80162a14..0x80162ac3  size 176 B
 * body sha256 3148dd70b8cc99d984f59dc79683abbf4f7417e78489c66698870d899a048aa2
 * provider record sha256 88762d8eacc3ec8c4bf627cefc6233167ac90fd85858d186b575656cdc3b4780
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162a14(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined2 *)(param_1 + 0x66) = 0x400;
    *(undefined1 *)(param_1 + 0x2c5) = 0;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0;
    bVar2 = func_0x80033604();
    *(byte *)(param_1 + 0x2be) = (bVar2 & 0xf) + 0x1e;
    *(undefined2 *)(param_1 + 0x66) = 0x800;
  }
  func_0x80033648(param_1);
  if (((**(uint **)(param_1 + 0x214) & 0x20000) != 0) && (*(char *)(param_1 + 0x2c5) == '\0')) {
    uVar3 = FUN_80163a30(param_1,1);
    *(undefined1 *)(param_1 + 0x2c5) = uVar3;
  }
  return;
}
