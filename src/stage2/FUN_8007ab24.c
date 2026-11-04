/* FUN_8007ab24
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ab24  body 0x8007ab24..0x8007ac13  size 240 B
 * body sha256 96d7d553b0c6d2568d947cedd38b17ec65f2035db88be52b533c2cbfb27b8a54
 * provider record sha256 f2bca02000b34954f1a6d3c4674c1ce4cef92d5f059d7540dc0e95fecfce0d11
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ab24(int param_1)

{
  if ((*(ushort *)(param_1 + 0x1aa) & 0x100) != 0) {
    *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xfeff;
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x11a0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xd38,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x178,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x2f0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x758,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xeb0,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0x1318,1);
    FUN_8008794c(param_1,*(int *)(param_1 + 0x234) + 0xbc0,1);
    FUN_8008794c(param_1,*(undefined4 *)(param_1 + 0x234),1);
  }
  return;
}
