/* FUN_8003d79c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003d79c  body 0x8003d79c..0x8003d91f  size 388 B
 * body sha256 21717aabe21b8dd01877607c84341830a932b357aff775f4d02e0ca90beb1986
 * provider record sha256 248f57f5ed9b9df4f9958084a9f71c05b02132f0d97de1c61906432d73e35d55
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003d79c(void)

{
  ushort *puVar1;
  ushort uVar2;
  undefined1 *puVar3;
  int iVar4;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar4 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  if ((iVar4 != 0) && (iVar4 < *(short *)(DAT_800ebb94 + 0x36))) {
    DAT_800ebb94[9] = 0;
    puVar3 = DAT_800ebb94;
    *(undefined2 *)(DAT_800ebb94 + 0xe) = 0;
    *(short *)(puVar3 + 0x36) = (short)iVar4;
  }
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar4 = FUN_80069f1c(&local_20,2,0x2000,0);
  if (iVar4 < local_1c) {
    DAT_800ebb94[9] = 0;
    *(undefined2 *)(DAT_800ebb94 + 0xe) = 0;
  }
  puVar3 = DAT_800ebb94;
  if (*(ushort *)(DAT_800ebb94 + 6) < 0x1001) {
    uVar2 = *(ushort *)(DAT_800ebb94 + 0x3a);
    *(undefined2 *)(DAT_800ebb94 + 4) = 0x1100;
    *(undefined2 *)(puVar3 + 6) = 0xa00;
    *(ushort *)(puVar3 + 0x3a) = uVar2 + (short)(((uint)uVar2 * 0x1e) / 100);
    FUN_8003d200();
  }
  else {
    *DAT_800ebb94 = 0;
    DAT_800ebb94[1] = 0x39;
    puVar3 = DAT_800ebb94;
    puVar1 = (ushort *)(DAT_800ebb94 + 6);
    *(short *)(DAT_800ebb94 + 4) =
         (short)((longlong)(int)(uint)*(ushort *)(DAT_800ebb94 + 4) * 0x466666667 >> 0x22);
    *(ushort *)(puVar3 + 6) = *puVar1 - (short)(((uint)*puVar1 * 300) / 1000);
  }
  return;
}
