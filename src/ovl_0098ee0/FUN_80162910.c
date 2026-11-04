/* FUN_80162910
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162910  body 0x80162910..0x801629bb  size 172 B
 * body sha256 d071490dcf44ff020818207d58a6c50f829f523335aebdfe0b2a5d4f63a570ec
 * provider record sha256 8d0ea06e5a215481d68b9013a49622c4f92e767fcaf92f34370dbaaee5368d16
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162910(int param_1)

{
  int *piVar1;
  short sVar2;
  short *psVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  psVar3 = &DAT_801666b6;
  iVar6 = *(int *)(param_1 + 0x234);
  puVar4 = &DAT_801666b0;
  do {
    piVar1 = (int *)(psVar3 + 1);
    sVar2 = *psVar3;
    psVar3 = psVar3 + 6;
    uVar5 = uVar5 + 1;
    func_0x80037780((int)sVar2 | 0x5040000,(int)*(short *)(param_1 + 0x66),
                    iVar6 + *piVar1 * 0x178 + 0x38,puVar4);
    puVar4 = puVar4 + 0xc;
  } while (uVar5 < 7);
  return;
}
