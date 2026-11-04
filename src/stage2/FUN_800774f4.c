/* FUN_800774f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800774f4  body 0x800774f4..0x800777d7  size 740 B
 * body sha256 1e6b300493eda781d4c925606ad67a6539c71911e92180e8cda8018bffbe1e93
 * provider record sha256 e892b9c474dc443b65f4d28ccdf546d4936550769af336b607b90e3004a857bf
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800774f4(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  char *pcVar5;
  int iVar6;
  
  if ((DAT_800e10ec & 0x2000) == 0) {
    if (DAT_80119e70 == 1) {
      DAT_80119e71 = DAT_80119e71 + -1;
      if (DAT_80119e72 == '\x18') {
        uVar2 = ((_DAT_80119e7c >> 0x10) * 0x62) / 100;
        uVar3 = ((_DAT_80119e7c & 0xffff) * 0x62) / 100;
        _DAT_80119e7c = CONCAT22((short)uVar2,(short)uVar3);
        FUN_800793a4((int)(uVar2 * 0x10000) >> 0x10,(int)(uVar3 * 0x10000) >> 0x10);
      }
      iVar6 = 3;
      if (DAT_80119e71 == '\x01') {
        pcVar5 = (char *)&DAT_80119ef4;
        do {
          iVar6 = iVar6 + -1;
          if (*pcVar5 != '\0') {
            *pcVar5 = '\0';
            sVar4 = FUN_80079418((int)pcVar5[2],0);
            if (sVar4 != 0) {
              FUN_800790a4((int)pcVar5[2]);
            }
          }
          pcVar5 = pcVar5 + -8;
        } while (iVar6 != 0);
        if (DAT_80119e72 == '\x18') {
          _DAT_80119e7c = 0x7f007f;
          FUN_800793a4(0x7f,0x7f);
        }
        DAT_80119e70 = 2;
      }
    }
    else if (DAT_80119e70 < 2) {
      if (DAT_80119e70 == 0) {
        if ((5 < DAT_80119ee4) &&
           (bVar1 = DAT_80119ee4 == 6, DAT_80119ee4 = DAT_80119ee4 - 1, bVar1)) {
          DAT_80119ee4 = 0;
          sVar4 = FUN_80079418((int)DAT_80119ee6,0);
          if (sVar4 != 0) {
            FUN_800790a4((int)DAT_80119ee6);
          }
        }
        if ((5 < DAT_80119eec) &&
           (bVar1 = DAT_80119eec == 6, DAT_80119eec = DAT_80119eec - 1, bVar1)) {
          DAT_80119eec = 0;
          sVar4 = FUN_80079418((int)DAT_80119eee,0);
          if (sVar4 != 0) {
            FUN_800790a4((int)DAT_80119eee);
          }
        }
        if ((5 < DAT_80119ef4) &&
           (bVar1 = DAT_80119ef4 == 6, DAT_80119ef4 = DAT_80119ef4 - 1, bVar1)) {
          DAT_80119ef4 = 0;
          sVar4 = FUN_80079418((int)DAT_80119ef6,0);
          if (sVar4 != 0) {
            FUN_800790a4((int)DAT_80119ef6);
          }
        }
      }
    }
    else if (DAT_80119e70 == 2) {
      if ((DAT_800e10ec & 0x2000000) == 0) {
        FUN_80078b40(0);
      }
      DAT_80119e71 = '\0';
      DAT_80119e70 = 0;
    }
  }
  return;
}
