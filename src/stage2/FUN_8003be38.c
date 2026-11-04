/* FUN_8003be38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003be38  body 0x8003be38..0x8003bfb3  size 380 B
 * body sha256 b883b4f1697c57ed58e0b18dae4965e9d09d9cddbb42b7342396f62445d8c81b
 * provider record sha256 736d4033f4080f1bb28d3ef3f87a3a82ef910750183dc4fcc66b6582cd0c45bb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003be38(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(DAT_800ebb94 + 0x12) == 0) {
    if (*(short *)(DAT_800ebb94 + 0xe) < 1) {
      *(undefined2 *)(DAT_800ebb94 + 0x12) = 1;
    }
  }
  else if (*(short *)(DAT_800ebb94 + 0xe) < *(short *)(DAT_800ebb94 + 0x4a)) {
    uVar2 = FUN_80033604();
    *(ushort *)(DAT_800ebb94 + 0xc) =
         (short)*(char *)(DAT_800ebb94 + 0x43) *
         (((short)(uVar2 & 0xff) + (short)((uVar2 & 0xff) / 0x46) * -0x46 & 0xffU) + 0x32);
    uVar2 = FUN_80033604();
    *(short *)(DAT_800ebb94 + 0x10) =
         (short)*(char *)(DAT_800ebb94 + 0x43) * (short)((uVar2 & 0xff) % 0x32);
    uVar2 = FUN_80033604();
    iVar1 = DAT_800ebb94;
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 0;
    iVar3 = (uVar2 & 0xff) % 0x14 + 0x28;
    *(short *)(iVar1 + 0xe) = (short)iVar3;
    *(short *)(iVar1 + 0x42) = (short)-*(char *)(iVar1 + 0x43);
    *(short *)(iVar1 + 0x4a) = (short)((iVar3 * -3) / 10);
  }
  return;
}
