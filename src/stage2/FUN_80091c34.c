/* FUN_80091c34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091c34  body 0x80091c34..0x80091eb3  size 640 B
 * body sha256 32b7c7ecf687e0dbc675db24cb38e995d101626d53c1211af7874e53778a8010
 * provider record sha256 2e71fe578dfc4cf0a4b7bceb4d284fd3b482ee00931d9ff50f68a7502611c1cc
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80091c34(void)

{
  byte bVar1;
  byte bVar3;
  int iVar2;
  
  bVar1 = DAT_8012bfb2;
  if (DAT_8012bf9a == '\0') {
    if (DAT_8012bfc1 == '\0') {
      bVar3 = DAT_8012bfc0 + 4;
      if (0x50 < DAT_8012bfc0) {
        DAT_8012bfc1 = '\x01';
        bVar3 = DAT_8012bfc0 + 4;
      }
    }
    else {
      if (DAT_8012bfc0 < 10) {
        DAT_8012bfc1 = '\0';
      }
      bVar3 = DAT_8012bfc0 - 4;
    }
    DAT_8012bfc0 = bVar3;
    if ((DAT_800e10ec < 0) && (1 < DAT_8012bfb2)) {
      if (((DAT_800df90c & 0x1000) != 0) &&
         ((1 < (byte)(&DAT_8012f970)[DAT_8012bfb2] &&
          (iVar2 = FUN_800837ac(&DAT_800e8d94,(&DAT_8012f970)[DAT_8012bfb2]), iVar2 != 0)))) {
        DAT_8012bfb2 = (&DAT_8012f970)[DAT_8012bfb2];
      }
      if ((((DAT_800df90c & 0x4000) != 0) && (1 < (byte)(&LAB_8012f988)[DAT_8012bfb2])) &&
         (iVar2 = FUN_800837ac(&DAT_800e8d94,(&LAB_8012f988)[DAT_8012bfb2]), iVar2 != 0)) {
        DAT_8012bfb2 = (&LAB_8012f988)[DAT_8012bfb2];
      }
      if (bVar1 != DAT_8012bfb2) {
        DAT_8012bf9a = 1;
        FUN_80077adc(0x4040000,0);
        return;
      }
    }
    if (((DAT_800df918 & 0x4000) != 0) || ((DAT_800df918 & 0x6000) != 0)) {
      FUN_80077adc(0x4050000,0);
      DAT_8012bf99 = 0;
    }
  }
  else if (DAT_8012bf9a == '\x01') {
    FUN_800479c8(DAT_800c52dc + 0x44807U & 0xfffffff8,&DAT_8012f5a0,
                 *(undefined2 *)
                  (&DAT_8012f8ec + (uint)*(ushort *)(&DAT_80130cba + (uint)DAT_8012bfb2 * 8) * 2),1)
    ;
    FUN_80090e10();
    DAT_8012bfc1 = '\0';
    DAT_8012bfc0 = 4;
    DAT_8012bf9a = '\0';
  }
  return;
}
