/* FUN_80091eb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091eb4  body 0x80091eb4..0x80091fcb  size 280 B
 * body sha256 f0347fe50775c258869dbba28f60b18449456fd1be02d69a4c3cc39d04b34242
 * provider record sha256 216a9be7cdfaace59e0dd6c11a0199fc74094167f1cd2a7f20cb0c137054bafd
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80091eb4(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  
  DAT_8012bf98 = 1;
  DAT_8012bf99 = 2;
  DAT_8012bfb2 = FUN_80091738((int)DAT_800e8ca8,(int)DAT_800e8caa);
  FUN_800479c8(DAT_800c52dc + 0x44807U & 0xfffffff8,&DAT_8012f5a0,
               *(undefined2 *)
                (&DAT_8012f8ec + (uint)*(ushort *)(&DAT_80130cba + (uint)DAT_8012bfb2 * 8) * 2));
  uVar2 = 0x100;
  uVar3 = 0x100;
  DAT_8012bff0 = 0;
  DAT_8012bff2 = 0;
  FUN_80090e10();
  FUN_800274f8(0x200,0xffffe800,7,1,uVar2,uVar3);
  do {
    FUN_8004cd88(1);
    FUN_80097fd0();
    FUN_8009109c();
    iVar1 = FUN_8002767c(0);
  } while (iVar1 == 0);
  FUN_80077adc(0x4090000,0);
  return;
}
