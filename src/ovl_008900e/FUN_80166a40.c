/* FUN_80166a40
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80166a40  body 0x80166a40..0x80166b0b  size 204 B
 * body sha256 5ac10f109e99a42daee487f1b847d220055a991ef9ea750e7c9140537ce796c6
 * provider record sha256 25388b4a41d91d1be16081f5135553c246fec196ddf929c4c70356ce7a4b8db8
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166a40(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  
  if (*(char *)((int)param_1 + 5) != -1) {
    *(undefined1 *)((int)param_1 + 0x2cb) = *(undefined1 *)((int)param_1 + 5);
    bVar1 = DAT_80168d60 == *(byte *)(param_1 + 3);
    param_1[0xb1] = 0x800e1130;
    if (bVar1) {
      DAT_80168d60 = 0;
    }
    *(undefined1 *)((int)param_1 + 0x2b5) = 2;
    *(undefined1 *)((int)param_1 + 5) = 0xff;
    FUN_80166b0c(param_1);
    if (*(char *)((int)param_1 + 0x26e) != '\0') {
      *param_1 = *param_1 & 0xfffffff1;
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xfd0f;
    }
  }
  (*(code *)(&PTR_FUN_80168d14)[*(byte *)((int)param_1 + 0x26e)])(param_1,param_2,param_3);
  return;
}
