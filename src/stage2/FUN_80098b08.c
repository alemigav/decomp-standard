/* FUN_80098b08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80098b08  body 0x80098b08..0x80098c07  size 256 B
 * body sha256 56da6c640b615b195e23d8b52c47ceccc1f9f56a772d6dbaf440b1d25798d207
 * provider record sha256 020348ec5ddf93f6d0c8ea97ecdaf59a15f30c25b20f203e2aaf6098a2cf8704
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80098b08(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  
  FUN_80043620();
  sVar7 = 0x187;
  sVar6 = 0x38;
  sVar5 = 0x30;
  iVar2 = DAT_800c52dc + 0x3f800;
  iVar3 = 2;
  do {
    sVar7 = sVar7 + -0xba;
    sVar6 = sVar6 + -0x10;
    iVar4 = iVar3 + -1;
    sVar5 = sVar5 + -0x10;
    sVar1 = sVar6;
    if ((uint)DAT_8012bf9a == iVar3 + 3U) {
      sVar1 = sVar5;
    }
    FUN_800478ac(iVar2,sVar1,8);
    FUN_800478b8(iVar2,DAT_8012bfe4 + sVar7 + -10,DAT_8012bfe6 + 0x36);
    DAT_800df8b4 = FUN_80043988(DAT_800df8b4,iVar2,0,0);
    iVar2 = iVar2 + 0x28;
    iVar3 = iVar4;
  } while (iVar4 != 0);
  return;
}
