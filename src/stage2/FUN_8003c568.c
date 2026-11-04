/* FUN_8003c568
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c568  body 0x8003c568..0x8003c61b  size 180 B
 * body sha256 d8988d6cd8e5620ddc542b3e2bb73be4242369ffb3baa2f94250cbd452cf98a2
 * provider record sha256 9f00db09e1d96fac77505a0294ec04a23e502b684e92fae2f4e803a435f6d439
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c568(void)

{
  ushort *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar5;
  ushort uVar4;
  
  puVar2 = DAT_800ebb94;
  DAT_800ebb94[9] = 0;
  puVar2[2] = 0;
  puVar3 = DAT_800ebb94;
  *(undefined2 *)(puVar2 + 0xe) = 0;
  *puVar3 = 0x13;
  DAT_800ebb94[1] = 0x1d;
  *(undefined2 *)(DAT_800ebb94 + 0xc) = 0xb4;
  bVar5 = FUN_80033604();
  DAT_800ebb94[8] = -10 - bVar5 % 0xb;
  uVar4 = FUN_80033604();
  puVar2 = DAT_800ebb94;
  puVar1 = (ushort *)(DAT_800ebb94 + 0x12);
  *(ushort *)(DAT_800ebb94 + 0x42) = (uVar4 & 7) + 0x26;
  *(ushort *)(puVar2 + 0x12) = *puVar1 & 0xfffe;
  return;
}
