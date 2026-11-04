/* FUN_80090584
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80090584  body 0x80090584..0x80090703  size 384 B
 * body sha256 092ef226240f7630b301d859776705bd48d58e416548d029a5260e58c083d6a0
 * provider record sha256 bc2a02c28b1b2ee08fff0d89d8a2123dc4a8bdc1212260187e69e143514b3ad0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80090584(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = DAT_8012bfa9 * 8;
  if (DAT_8012bfa9 == 3) {
    if (DAT_800e901b != 0xff) {
      if (param_1 == 0) {
        if ((int)(char)(DAT_8012bfaa + 1) <= (int)(DAT_800e901b - 1)) {
          DAT_8012bfaa = DAT_8012bfaa + 1;
          return;
        }
        DAT_8012bfaa = 0;
      }
      else {
        DAT_8012bfaa = DAT_8012bfaa - 1;
        if ((int)((uint)DAT_8012bfaa << 0x18) < 0) {
          DAT_8012bfaa = DAT_800e901b - 1;
          return;
        }
      }
      return;
    }
  }
  else {
    iVar1 = 7;
    while( true ) {
      if ((&DAT_800e8ff4)[iVar3 + iVar1] != -1) {
        iVar2 = iVar2 + 1;
      }
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
    }
    if (iVar2 != 0) {
      if (param_1 == 0) {
        do {
          DAT_8012bfaa = DAT_8012bfaa + 1;
          if ('\a' < (char)DAT_8012bfaa) {
            DAT_8012bfaa = 0;
          }
        } while ((&DAT_800e8ff4)[iVar3 + (char)DAT_8012bfaa] == -1);
        return;
      }
      do {
        DAT_8012bfaa = DAT_8012bfaa - 1;
        if ((int)((uint)DAT_8012bfaa << 0x18) < 0) {
          DAT_8012bfaa = 7;
        }
      } while ((&DAT_800e8ff4)[iVar3 + (char)DAT_8012bfaa] == -1);
      return;
    }
  }
  return;
}
