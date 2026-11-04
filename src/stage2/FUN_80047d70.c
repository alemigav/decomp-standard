/* FUN_80047d70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047d70  body 0x80047d70..0x80047fe3  size 628 B
 * body sha256 d6b224e80d99956a59af4a7c37a2282c12af163ab4e170a335cadf7e6f98d81e
 * provider record sha256 fe001d2c5458db830e56e260821d75e08cc8d0a52f8017409384259e055b48be
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
float FUN_80047d70(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  fVar1 = (float)FUN_80048060(param_2 * param_2 + param_1 * param_1);
  fVar2 = param_1;
  if (param_1 < 0.0) {
    fVar2 = -param_1;
  }
  fVar3 = param_2;
  if (param_2 < 0.0) {
    fVar3 = -param_2;
  }
  if (fVar3 <= fVar2) {
    if (param_1 < 0.0) {
      iVar4 = (int)(param_2 * fVar1 * 4096.0);
      if (iVar4 < 0) {
        fVar2 = -*(float *)(&DAT_800f14bc + iVar4 * -4);
      }
      else {
        fVar2 = *(float *)(&DAT_800f14bc + iVar4 * 4);
      }
      fVar2 = fVar2 + -1.5707964;
    }
    else {
      iVar4 = (int)(param_2 * fVar1 * 4096.0);
      if (iVar4 < 0) {
        fVar2 = -*(float *)(&DAT_800f14bc + iVar4 * -4);
      }
      else {
        fVar2 = *(float *)(&DAT_800f14bc + iVar4 * 4);
      }
      fVar2 = 1.5707964 - fVar2;
    }
  }
  else if (param_2 < 0.0) {
    if (param_1 < 0.0) {
      iVar4 = (int)(param_1 * fVar1 * 4096.0);
      if (iVar4 < 0) {
        fVar2 = -*(float *)(&DAT_800f14bc + iVar4 * -4);
      }
      else {
        fVar2 = *(float *)(&DAT_800f14bc + iVar4 * 4);
      }
      fVar2 = -(fVar2 + 3.1415927);
    }
    else {
      iVar4 = (int)(param_1 * fVar1 * 4096.0);
      if (iVar4 < 0) {
        fVar2 = -*(float *)(&DAT_800f14bc + iVar4 * -4);
      }
      else {
        fVar2 = *(float *)(&DAT_800f14bc + iVar4 * 4);
      }
      fVar2 = 3.1415927 - fVar2;
    }
  }
  else {
    iVar4 = (int)(param_1 * fVar1 * 4096.0);
    if (iVar4 < 0) {
      fVar2 = -*(float *)(&DAT_800f14bc + iVar4 * -4);
    }
    else {
      fVar2 = *(float *)(&DAT_800f14bc + iVar4 * 4);
    }
  }
  return fVar2;
}
