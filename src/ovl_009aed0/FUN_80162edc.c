/* FUN_80162edc
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162edc  body 0x80162edc..0x80162f83  size 168 B
 * body sha256 070e4ba222d0d18590848af681d5d86fd603ee877c6bc74dd5332c66b1ec89f8
 * provider record sha256 7f8359a2425605f19a99360cb0e842c8d88434b4f73f461b9e1b359a1d4f6d41
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162edc(int param_1)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar4 = *(int *)(param_1 + 0x234);
  puVar2 = &DAT_8016652c;
  do {
    uVar1 = uVar3 + 0x90;
    uVar3 = uVar3 + 1;
    func_0x800385a4((int)*(short *)(puVar2 + 6) | 0x5030000,
                    (int)*(short *)(param_1 + 0x66) << 0x10 | uVar1,
                    iVar4 + *(int *)(puVar2 + 8) * 0x178 + 0x38,puVar2);
    puVar2 = puVar2 + 0xc;
  } while (uVar3 < 0xe);
  return;
}
