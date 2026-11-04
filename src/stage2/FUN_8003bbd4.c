/* FUN_8003bbd4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bbd4  body 0x8003bbd4..0x8003bd83  size 432 B
 * body sha256 b08d0b25b2ee805935dbf376629ad5719ad8724e0658dfd98dfa626542ec0313
 * provider record sha256 e5b97a82f3e9ecfd9fdb4a91aecdb550c2f0d7949bf418d85f80112ce6c5a13c
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003bbd4(void)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar3 = FUN_80060f78(&local_20,800,0x14);
  iVar2 = DAT_800ebb94;
  if (iVar3 == 0) {
    if (*(char *)(DAT_800ebb94 + 0x1b) < '\x14') {
      puVar1 = (ushort *)(DAT_800ebb94 + 4);
      *(char *)(DAT_800ebb94 + 0x1b) = *(char *)(DAT_800ebb94 + 0x1b) + '\x01';
      *(ushort *)(iVar2 + 4) = *puVar1 + (short)(((uint)*puVar1 * 0x26) / 1000);
    }
    *(short *)(DAT_800ebb94 + 6) =
         (short)((longlong)(int)(uint)*(ushort *)(DAT_800ebb94 + 6) * 0x4051eb851f >> 0x26);
  }
  else {
    if (*(byte *)(iVar3 + 8) < 0x10) {
      if ((*(byte *)(DAT_800ebb94 + 0x1e) & 8) != 0) {
        DAT_800e13e4 = 0x1518;
        DAT_800e13e6 = 0x1e;
        DAT_800e139f = DAT_800e139f | 0x80;
      }
      FUN_80052bd0(8,0);
      FUN_80052d10(0xe,0xb4,0x3c,0);
    }
    else if ((*(byte *)(DAT_800ebb94 + 0x1e) & 8) != 0) {
      DAT_800e900f = DAT_800e900f | 1;
    }
    (*(code *)(&PTR_FUN_800eb9b0)[*(byte *)(DAT_800ebb94 + 2)])();
  }
  return;
}
