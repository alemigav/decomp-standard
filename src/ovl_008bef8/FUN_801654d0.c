/* FUN_801654d0
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801654d0  body 0x801654d0..0x801655f3  size 292 B
 * body sha256 02a05e0c9cc652ed8f23ca709c1ccab27d9c9044049e6c507a7b9bb3f1dcd63e
 * provider record sha256 1a6bbc24a9d27c546e1db8833b9c2f0e376b3c6bbb42a0615482293027f104a6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801654d0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_2 + -1;
  if (param_2 != 0) {
    do {
      if (param_6 == 0) {
        uVar1 = func_0x80033604();
        uVar1 = uVar1 & 7;
      }
      else {
        uVar1 = func_0x80033604();
        uVar1 = (uVar1 & 0xff) % 0x18;
      }
      iVar3 = uVar1 * 0xc;
      iVar2 = func_0x80033604();
      iVar4 = iVar4 + -1;
      FUN_80165e14(param_1,param_3,param_4,param_5,
                   (int)*(short *)(&DAT_8016613a + iVar3) + ((iVar2 << 0x18) >> 0x14),
                   *(undefined4 *)(&DAT_8016613c + iVar3),&DAT_80166134 + iVar3);
    } while (iVar4 != -1);
  }
  return;
}
