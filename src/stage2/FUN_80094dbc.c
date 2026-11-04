/* FUN_80094dbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80094dbc  body 0x80094dbc..0x8009527f  size 84 B
 * body sha256 dc43896abe75fa571979144b83c3c62b3c329e26bf4f0f4c00de0586a8cd4dbc
 * provider record sha256 c57c7b928d1b1848ca707ce4a130213a4120191ba01613d241184d689598cc5d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80094dbc(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined1 *puVar4;
  char cVar6;
  undefined4 uVar5;
  int iVar7;
  undefined *puVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  undefined2 *puVar12;
  
  puVar4 = DAT_800dfbe0;
  switch(DAT_8012bf9a) {
  case '\0':
    if ((DAT_8010b294 & 0x80) != 0) {
      return;
    }
    goto LAB_800951d0;
  case '\x01':
    if ((DAT_8010b294 & 0x80) == 0) {
      if ((DAT_8010b294 & 1) == 0) {
        if (DAT_8012bf9b == 0) {
          uVar11 = FUN_8008c4b8(0);
        }
        else {
          uVar11 = (uint)DAT_8012bfaf;
        }
        if (DAT_800e110c < 0) {
          cVar6 = 'N';
        }
        else {
          cVar6 = 'R';
        }
        if (DAT_800e8605 == cVar6) {
          FUN_80077adc(0x4060000,0);
          uVar11 = 10;
        }
        iVar7 = uVar11 * 4;
        DAT_8012fe54 = (short)(char)(&DAT_8012fe1c)[iVar7];
        DAT_8012fe56 = (short)(char)(&DAT_8012fe1d)[iVar7];
        DAT_8012fe5c = (int)(char)(&DAT_8012fe1e)[iVar7];
        DAT_8012bf9c = (&DAT_8012fe1f)[iVar7];
        DAT_8012bf9a = '\x02';
      }
      else {
        DAT_8012bf9a = '\x04';
      }
    }
    break;
  case '\x02':
    if (DAT_8012bf9c != 0) {
      DAT_8012fe54 = DAT_8012fe54 + DAT_8012bf9c + 8;
      DAT_8012fe56 = DAT_8012fe56 + DAT_8012fe5c._2_2_;
      DAT_8012fe58 = DAT_8012fe58 + -6;
      if (DAT_8012fe58 < 0x2e) {
        DAT_8012fe58 = 0x2d;
      }
      DAT_8012fe5a = DAT_8012fe5a + -4;
      if (DAT_8012fe5a < 0x1f) {
        DAT_8012fe5a = 0x1e;
      }
      DAT_8012bf9c = DAT_8012bf9c - 1;
    }
    DAT_8012fe64 = DAT_8012fe64 + '\x01';
    if (DAT_8012fe64 != '\x12') {
      return;
    }
  case '\x04':
  case '\x05':
  case '\x06':
  case '\a':
  case '\b':
  case '\t':
  case '\n':
  case '\v':
  case '\f':
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x10':
  case '\x11':
LAB_80095200:
    DAT_8012bf9a = DAT_8012bf9a + '\x01';
    break;
  case '\x03':
    pbVar1 = DAT_800dfbe0 + 1;
    *DAT_800dfbe0 = 0;
    if ((*pbVar1 & 0x80) == 0) {
      puVar12 = (undefined2 *)(puVar4 + 0xc);
    }
    else {
      puVar12 = (undefined2 *)(puVar4 + 0x14);
    }
    if (DAT_8012bf9b == 0) {
      if (DAT_800e110c < 0) {
        uVar5 = 0x4e;
        if (DAT_800e8605 != 'N') goto LAB_800950b4;
      }
      else {
        uVar5 = 0x52;
        if (DAT_800e8605 != 'R') {
LAB_800950b4:
          FUN_8008c8a8(DAT_800e8605,puVar12[1],_DAT_8013a390);
          goto LAB_800950cc;
        }
      }
      FUN_8008c314(10,uVar5,1,0);
    }
    else {
      (&DAT_800e8ec9)[(uint)DAT_8012bfaf * 4] =
           (&DAT_800e8ec9)[(uint)DAT_8012bfaf * 4] + *(char *)((int)puVar12 + 3);
    }
LAB_800950cc:
    DAT_800e8c7e = *puVar12;
    if (DAT_800e8ca8 < 4) {
      uVar2 = puVar12[2];
      puVar8 = &DAT_800e8d48;
    }
    else {
      uVar2 = puVar12[2];
      puVar8 = &DAT_800e8d68;
    }
    FUN_80083758(puVar8,uVar2);
    uVar11 = (uint)*(byte *)(puVar12 + 3);
    if (uVar11 < 0x20) {
      (&DAT_800e18f8)[uVar11 * 0xda] = 0;
    }
    if ((*(byte *)((int)puVar12 + 7) & 0x80) != 0) {
      uVar10 = (*(byte *)((int)puVar12 + 7) & 0x60) >> 5;
      if (uVar10 == 0) {
        uVar10 = 1;
      }
      FUN_80038e98(5,uVar10 * 8 + 7,&DAT_800e190c + uVar11 * 0x368);
    }
    FUN_8004ac04(0xaf0010,0xe400,6,0);
    DAT_8012bf9a = '\0';
    break;
  case '\x12':
LAB_800951d0:
    FUN_80077adc(0x4050000,0);
    DAT_8012bf99 = 0;
    break;
  case '\x13':
    bVar9 = DAT_8012bf9b + 1;
    bVar3 = DAT_8012bf9b < 0x33;
    DAT_8012bf9b = bVar9;
    if (bVar3) {
      return;
    }
    goto LAB_80095200;
  case '\x14':
    DAT_8012bf9a = '\x02';
    DAT_8012bf9b = 0;
    DAT_8012fe54 = 0xe;
    DAT_8012fe56 = 2;
    DAT_8012fe5c = -3;
    DAT_8012bf9c = 0xf;
    FUN_80077adc(0x4060000,0);
  }
  return;
}
