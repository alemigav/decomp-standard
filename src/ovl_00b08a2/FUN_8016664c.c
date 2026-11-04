/* FUN_8016664c
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x8016664c  body 0x8016664c..0x80166703  size 184 B
 * body sha256 d3b34bd1100e5c22552ccfc96b723fc6a65af3a714478f6f1e7425151b21f058
 * provider record sha256 a45a1977f5c14730f71afbc6f081b39edf958006e4abc3d0d17c087b564aea19
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016664c(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x234);
  func_0x80036290(param_1,iVar4,&DAT_80167340);
  func_0x80036290(param_1,iVar4,&DAT_801673c8);
  func_0x80036290(param_1,iVar4,&DAT_80167440);
  iVar2 = _DAT_80131734 + 1;
  if (_DAT_80131734 != 0) {
    _DAT_80131734 = iVar2;
    if (iVar2 == 8) {
      _DAT_80131734 = 0;
    }
    iVar2 = (int)*(short *)(*(int *)(*(int *)(iVar4 + 200) + 4) + 0xe);
    if (0 < iVar2) {
      iVar3 = 1;
      do {
        bVar1 = iVar3 < iVar2;
        iVar3 = iVar3 + 1;
      } while (bVar1);
    }
  }
  func_0x80036734(param_1,iVar4);
  return;
}
