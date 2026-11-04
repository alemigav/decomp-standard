/* FUN_80036dc4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036dc4  body 0x80036dc4..0x80036e6f  size 172 B
 * body sha256 dc19725fbf24b340d62183b54a4a5bd40a71d24db2663e0c7c5a9e39196a95a4
 * provider record sha256 e0d7bc3eec019196e4c786511b12f30ec54d26b9e4db3ce9cb057a852b521995
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_80036dc4(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (*(byte *)(param_1 + 0x1e8) != param_2) {
    *(char *)(param_1 + 0x1e8) = (char)param_2;
    *(undefined1 *)(param_1 + 0x1e9) = 0;
    *(char *)(param_1 + 0x1ea) = (char)param_3;
  }
  FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
  if (param_3 + 1U == 0) {
    trap(0x1c00);
  }
  iVar1 = FUN_8008a994(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),
                       0x1000 / (param_3 + 1U) | param_4 << 0x10);
  if (iVar1 == 0) {
    FUN_80032b5c(param_1,0);
  }
  return iVar1 != 0;
}
