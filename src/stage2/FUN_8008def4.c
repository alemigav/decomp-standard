/* FUN_8008def4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008def4  body 0x8008def4..0x8008dfa3  size 176 B
 * body sha256 d1e5431c71500bff69e7b69ef8e4148632c6e4b1420311d657bfa6cb1b8d6dbf
 * provider record sha256 f6d10b5a4d40109a10625b34bae81d2adfa2ae6841e7342ddf3bda70497504d8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8008def4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_8012bfae = 0;
  if ((byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] < 0x14) {
    if (DAT_8012bfa0 == DAT_8012bfa4) {
      _UNK_800e8b4e = 0;
      DAT_8012bf9a = 4;
      DAT_8012bf9b = 0;
      DAT_8012bfa0 = 0x80;
      DAT_8012bfa2 = 0;
      DAT_8012bfae = 0;
      _UNK_8012f520 = 0;
      return;
    }
    _UNK_800e8b4e = 0;
    DAT_8012bf9a = 4;
    DAT_8012bf9b = 0;
    DAT_8012bfa0 = DAT_8012bfa4;
    DAT_8012bfa2 = (&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4];
    DAT_8012bfae = 0;
    _UNK_8012f520 = 0;
    return;
  }
  switch(DAT_8012bf9c) {
  case 0:
    if ((byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4] < 0x1e) {
      uVar2 = 5;
LAB_8008e16c:
      FUN_8004ac04(0xaf0010,0xe400,uVar2,0);
      DAT_8012bf9c = 1;
      return;
    }
    switch((&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4]) {
    case 0x23:
                    /* WARNING: Read-only address (ram,0x800e8b4e) is written */
      _UNK_800e8b4e = 1;
      break;
    default:
      iVar1 = FUN_800837ac(&DAT_800e1114,(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4]);
      if (iVar1 != 0) {
        DAT_8012bf9c = 3;
        return;
      }
      uVar2 = 7;
      goto LAB_8008e16c;
    case 0x26:
      break;
    case 0x28:
                    /* WARNING: Read-only address (ram,0x8012f520) is written */
      DAT_800e13e4 = 0;
      DAT_8012bffa = '\x02';
      goto LAB_8008e118;
    case 0x29:
      break;
    case 0x2a:
                    /* WARNING: Read-only address (ram,0x8012f520) is written */
      break;
    case 0x2b:
      goto LAB_8008e100;
    case 0x2c:
                    /* WARNING: Read-only address (ram,0x8012f520) is written */
      break;
    case 0x2d:
      goto LAB_8008e100;
    case 0x2e:
LAB_8008e100:
                    /* WARNING: Read-only address (ram,0x8012f520) is written */
      DAT_800e13e4 = 0;
      DAT_8012bffa = '\x03';
      goto LAB_8008e118;
    }
    DAT_8012bffa = '\x01';
LAB_8008e118:
                    /* WARNING: Read-only address (ram,0x8012f520) is written */
    _UNK_8012f520 = 0;
    DAT_8012bf9c = 4;
    break;
  case 1:
    if ((DAT_8010b294 & 0x80) == 0) {
      DAT_8012bf9a = 4;
      DAT_8012bf9b = 0;
    }
    break;
  case 2:
    FUN_8008c314(DAT_8012bfa4,0,0,0);
    FUN_8008cc1c((uint)(DAT_8012bfa4 >> 1) + (uint)DAT_8012bfa4);
    DAT_8012bf9b = 1;
    DAT_8012bf9c = 2;
    DAT_8012bf9e = 0;
    DAT_8012bf9d = 0;
    break;
  case 3:
    DAT_800e8c7c = (ushort)(byte)(&DAT_800e8ec8)[(uint)DAT_8012bfa4 * 4];
    DAT_8012bf99 = 0;
    break;
  case 4:
    if (DAT_8012bffa == '\0') {
      DAT_8012bf9c = 2;
      DAT_800e1320 = DAT_800e1320 & 0xefff;
      if (-1 < DAT_800e1322) {
        DAT_800e1322 = 0;
      }
    }
  }
                    /* WARNING: Read-only address (ram,0x800e8b4e) is written */
                    /* WARNING: Read-only address (ram,0x8012f520) is written */
  return;
}
