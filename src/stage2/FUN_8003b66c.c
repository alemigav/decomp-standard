/* FUN_8003b66c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b66c  body 0x8003b66c..0x8003b77f  size 276 B
 * body sha256 423162c0d8610c1c4f5072463975b026114458ef2a311423c30adc1e68034237
 * provider record sha256 c7564070a92ce75d0cfe0603fa6e6e18cf2533454d4618b2b1fa923f50095457
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b66c(void)

{
  ushort *puVar1;
  undefined1 *puVar2;
  byte bVar5;
  undefined4 uVar3;
  uint uVar4;
  int local_20;
  int local_1c;
  int local_18;
  
  puVar2 = DAT_800ebb94;
  puVar1 = (ushort *)(DAT_800ebb94 + 0x2a);
  *(undefined2 *)(DAT_800ebb94 + 0x18) = 0xb003;
  *(ushort *)(puVar2 + 0x2a) = *puVar1 | 0x20;
  bVar5 = FUN_80033604();
  DAT_800ebb94[0x21] = bVar5 % 3;
  DAT_800ebb94[0x20] =
       *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)(byte)DAT_800ebb94[0x21] * 8 + 2);
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  uVar3 = FUN_80069f1c(&local_20,2,0x2000,0);
  puVar2 = DAT_800ebb94;
  *(undefined4 *)(DAT_800ebb94 + 0x14) = uVar3;
  *puVar2 = 0x3a;
  DAT_800ebb94[1] = 0x1c;
  DAT_800ebb94[0x1b] = 2;
  uVar4 = FUN_80033604();
  *(ushort *)(DAT_800ebb94 + 0x42) =
       ((short)(uVar4 & 0xff) + (short)((uVar4 & 0xff) / 3) * -3 & 0xffU) + 8;
  return;
}
