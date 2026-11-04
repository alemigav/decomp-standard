/* FUN_8016234c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x8016234c  body 0x8016234c..0x801624bf  size 372 B
 * body sha256 1b0cafbb663a71263ca4ae734681c39d6e6b3ea55a79c70a542329fb908049ae
 * provider record sha256 9eb1b8741acbf6b810a88e23bf4522a568ceff7f3ea1bb942ae7edbb54ef99f4
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016234c(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 700) != '\0') {
    *(char *)(param_1 + 700) = *(char *)(param_1 + 700) + -1;
  }
  if (*(char *)(param_1 + 0x2bd) != '\0') {
    *(char *)(param_1 + 0x2bd) = *(char *)(param_1 + 0x2bd) + -1;
  }
  if (*(char *)(param_1 + 0x2be) != '\0') {
    *(char *)(param_1 + 0x2be) = *(char *)(param_1 + 0x2be) + -1;
  }
  if (*(char *)(param_1 + 0x2d6) != '\0') {
    *(char *)(param_1 + 0x2d6) = *(char *)(param_1 + 0x2d6) + -1;
  }
  if (*(char *)(param_1 + 0x2d7) != '\0') {
    *(char *)(param_1 + 0x2d7) = *(char *)(param_1 + 0x2d7) + -1;
  }
  if (*(char *)(param_1 + 0x2ce) != '\0') {
    *(char *)(param_1 + 0x2ce) = *(char *)(param_1 + 0x2ce) + -1;
  }
  FUN_80166644(param_1);
  (*(code *)(&PTR_FUN_80167268)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  FUN_80166a44(param_1);
  FUN_80166584(param_1);
  func_0x800347b0(param_1,(int)(((uint)*(ushort *)(param_1 + 0x66) +
                                (uint)*(byte *)(param_1 + 0x2cd) * 0x800) * 0x10000) >> 0x10);
  FUN_80166978(param_1);
  *(undefined1 *)(param_1 + 0x2ca) = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(param_1 + 0x2cb) = *(undefined1 *)(param_1 + 6);
  *(undefined1 *)(param_1 + 0x2cc) = *(undefined1 *)(param_1 + 7);
  if ((*(char *)(param_1 + 0x2b5) != '\0') && (*(short *)(*(int *)(param_1 + 0x2d0) + 0x1f2) < 0)) {
    *(undefined1 *)(param_1 + 0x2b5) = 0;
  }
  if (((_DAT_800e1128 & 0x20) != 0) && (0 < _DAT_800e1322)) {
    _DAT_800e1128 = _DAT_800e1128 & 0xffdf;
  }
  return;
}
