/* FUN_80098a04
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80098a04  body 0x80098a04..0x80098b07  size 260 B
 * body sha256 567d858c15a5c6c761988f62a73303e0bb9afb94e819830d74538d75cf6761dd
 * provider record sha256 3e56e00f9bc5e8fd39e3d953d1293791b1618be05933beb9fd13bd5daa749b85
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80098a04(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  
  if (DAT_80112784 != 0) {
    FUN_8006c070(0);
  }
  iVar5 = 2;
  iVar2 = DAT_800c52dc + 0x3f800;
  FUN_800479c8(param_1 + 7U & 0xfffffff8,&DAT_8012f5bc,0x15c2,0);
  sVar4 = 0x38;
  do {
    iVar5 = iVar5 + -1;
    iVar3 = 2;
    puVar1 = (undefined4 *)(iVar2 + 0xc);
    do {
      FUN_8004786c(iVar2,0x80,0x80,0x80);
      FUN_800478ac(iVar2,sVar4,0);
      FUN_800479bc(iVar2,8,8);
      *(undefined2 *)((int)puVar1 + -2) = 0;
      *(undefined1 *)((int)puVar1 + -9) = 0;
      *puVar1 = &DAT_8012f5bc;
      puVar1 = puVar1 + 5;
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + 0x14;
    } while (iVar3 != 0);
    sVar4 = sVar4 + -8;
  } while (iVar5 != 0);
  return;
}
