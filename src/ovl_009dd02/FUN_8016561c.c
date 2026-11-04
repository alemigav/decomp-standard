/* FUN_8016561c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x8016561c  body 0x8016561c..0x801656bf  size 164 B
 * body sha256 89052d3c3c8301e48acf760d400ee4befe4108bcfb5a3c3483404637c345afa8
 * provider record sha256 704d8b5a0f842a9f1bd43675513eda65862420121437a2ea2199a95ef678fdfe
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016561c(uint *param_1)

{
  if (*(char *)(param_1 + 0xb7) != '\0') {
    DAT_800e1135 = 2;
    DAT_800e1136 = 0;
    DAT_800e1137 = 0;
    *(undefined1 *)(param_1 + 0xb7) = 0;
  }
  if (*(char *)((int)param_1 + 0x2d9) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    param_1[0x7a] = ((uint)*(byte *)((int)param_1 + 0x2cd) * 0xd + 0xc) * 0x1000000 + 0x3f00;
    _DAT_800e1128 = _DAT_800e1128 & 0xffbf;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 2;
    *param_1 = *param_1 | 4;
    return;
  }
  param_1[1] = 0x7000000;
  return;
}
