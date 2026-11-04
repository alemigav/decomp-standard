/* FUN_80094c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80094c08  body 0x80094c08..0x80094dbb  size 436 B
 * body sha256 c720526c63761beba7451585ec86624f9288344b0e51590a71438f8c5146d3c1
 * provider record sha256 53c57822e2b50e673e52531b6b652e1029dc6261d3bbb5aea1b63ef9a8b1e029
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80094c08(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar1 = FUN_8008c4b8(1);
  uVar5 = 0;
  if ((*(byte *)(DAT_800dfbe0 + 1) & 0x80) == 0) {
    iVar7 = DAT_800dfbe0 + 0xc;
  }
  else {
    iVar7 = DAT_800dfbe0 + 0x14;
  }
  uVar3 = 0x4e;
  if (-1 < DAT_800e110c) {
    uVar3 = 0x52;
  }
  uVar2 = (uint)DAT_800e8605;
  if (uVar2 == uVar3) {
    DAT_8012bf9a = 0x13;
    DAT_8012bf9b = 0;
  }
  else {
    if (uVar2 - 0x14 < 0xc) {
      puVar4 = &DAT_800c76b0;
      do {
        if ((uVar2 == *(byte *)(puVar4 + 0x8606)) &&
           ((int)(uint)*(byte *)((int)puVar4 + 0x21819) <=
            (int)((uint)(byte)(&DAT_8012ffa8)[(uint)*(byte *)(puVar4 + 0x8606) * 8] -
                 (uint)*(ushort *)(iVar7 + 2)))) {
          DAT_8012bfaf = (undefined1)uVar5;
          DAT_8012bf9b = 1;
          goto LAB_80094d68;
        }
        uVar5 = uVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar5 < DAT_800e8b38);
    }
    if (iVar1 < 1) {
      uVar6 = 1;
    }
    else {
      if ((iVar1 != 1) || (iVar1 = FUN_8008c408(DAT_800e8605), iVar1 == 0)) {
LAB_80094d68:
        FUN_8004ac04(0xaf0010,0xe400,0,0);
        DAT_8012bf99 = 3;
        DAT_8012bf9a = 1;
        return;
      }
      uVar6 = 4;
    }
    FUN_8004ac04(0xaf0010,0xe400,uVar6,0);
  }
  DAT_8012bf99 = 3;
  return;
}
