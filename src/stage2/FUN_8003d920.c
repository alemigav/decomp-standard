/* FUN_8003d920
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d920  body 0x8003d920..0x8003da97  size 376 B
 * body sha256 101f8dd0c4d0077c9ecab9753346fae6bb39ada1c792034a02b31ae9dc614524
 * provider record sha256 bfa2e33c06547ff444345c2b7af122dc37d8794b42e0847b321a5c17a2af42eb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d920(void)

{
  ushort *puVar1;
  char cVar2;
  undefined1 *puVar3;
  ushort uVar4;
  
  puVar3 = DAT_800ebb94;
  cVar2 = DAT_800ebb94[0x1b];
  if (cVar2 == '\x01') {
    if (*(short *)(DAT_800ebb94 + 0x42) == 0) {
      DAT_800ebb94[0x1b] = 0;
    }
    else {
      puVar1 = (ushort *)(DAT_800ebb94 + 4);
      uVar4 = *(ushort *)(DAT_800ebb94 + 6);
      *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + -1;
      *(short *)(puVar3 + 4) = (short)(((uint)*puVar1 * 0x370) / 1000);
      *(short *)(puVar3 + 6) = (short)(((uint)uVar4 * 800) / 1000);
    }
  }
  else if (cVar2 < '\x02') {
    if (cVar2 == '\0') {
      *DAT_800ebb94 = 0;
      *(undefined2 *)(puVar3 + 0x18) = 0;
    }
  }
  else if (cVar2 == '\x02') {
    if (*(short *)(DAT_800ebb94 + 0x42) == 0) {
      DAT_800ebb94[0x1b] = 1;
      uVar4 = FUN_80033604();
      *(ushort *)(DAT_800ebb94 + 0x42) = (uVar4 & 1) + 2;
    }
    else {
      puVar1 = (ushort *)(DAT_800ebb94 + 4);
      *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + -1;
      *(short *)(puVar3 + 4) = (short)(((uint)*puVar1 * 0x3f2) / 1000);
      *(short *)(puVar3 + 6) = (short)(((uint)*(ushort *)(puVar3 + 6) * 0x3ef) / 1000);
    }
  }
  return;
}
