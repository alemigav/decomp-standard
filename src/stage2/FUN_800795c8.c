/* FUN_800795c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800795c8  body 0x800795c8..0x80079663  size 156 B
 * body sha256 ea031c5fce31f8f8de13cb75519e6ccab543d2ddb8da0232f9a0be68c73cc03e
 * provider record sha256 63cd67c6094bd7fa993cee2041a41280c2016919b0e9d8bc2026a051a63936ee
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800795c8(int param_1)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + 0x1aa) & 0x800) != 0) {
    iVar1 = *(int *)(param_1 + 0x234);
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xf7ff;
    *(undefined4 *)(iVar1 + 0x10d0) = *(undefined4 *)(iVar1 + 0x16b0);
    *(undefined4 *)(iVar1 + 0x10d4) = *(undefined4 *)(iVar1 + 0x16b4);
    *(undefined4 *)(iVar1 + 0x10d8) = *(undefined4 *)(iVar1 + 0x16b8);
    *(undefined4 *)(iVar1 + 0x10dc) = *(undefined4 *)(iVar1 + 0x16bc);
    *(undefined2 *)(iVar1 + 0x10ec) = *(undefined2 *)(iVar1 + 0x16cc);
    *(undefined2 *)(iVar1 + 0x10ee) = *(undefined2 *)(iVar1 + 0x16ce);
    *(undefined4 *)(iVar1 + 0x10f4) = *(undefined4 *)(iVar1 + 0x16d4);
    *(undefined4 *)(iVar1 + 0x10f0) = *(undefined4 *)(iVar1 + 0x16d0);
    *(undefined4 *)(iVar1 + 0x1028) = 1;
    *(undefined4 *)(iVar1 + 0x1608) = 0;
  }
  FUN_8007acc0(param_1);
  FUN_8007ad14(param_1);
  return;
}
