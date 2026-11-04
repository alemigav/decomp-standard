/* FUN_80166d58
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80166d58  body 0x80166d58..0x80166e17  size 192 B
 * body sha256 3382368f27a60440f4f0006a7962a8c73c596259318f768fcc95fa46d9a7c620
 * provider record sha256 176d64c04f125c3bc970dd06ec2e49605a185201cef92c5b6b2529e82e523658
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80166d58(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(param_1 + 0x2c4);
  if ((*(byte *)(param_1 + 0x2cc) & 1) == 0) {
    if ((short)param_2 == 0x400) {
      iVar1 = func_0x8006a880(3,uVar3);
      iVar2 = *(int *)(param_1 + 0x30);
      goto LAB_80166e04;
    }
    iVar1 = func_0x8006a880(1,uVar3);
    iVar2 = *(int *)(param_1 + 0x30);
  }
  else {
    if ((int)((param_2 + -0x400 + (uint)*(byte *)(param_1 + 0x2cc) * 0x400) * 0x10000) >> 0x10 !=
        0x400) {
      iVar1 = func_0x8006a880(0,uVar3);
      iVar2 = *(int *)(param_1 + 0x28);
LAB_80166e04:
      return iVar1 + -0x9c4 < iVar2;
    }
    iVar1 = func_0x8006a880(2,uVar3);
    iVar2 = *(int *)(param_1 + 0x28);
  }
  return iVar2 < iVar1 + 0x9c4;
}
