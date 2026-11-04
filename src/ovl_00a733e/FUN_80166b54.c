/* FUN_80166b54
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80166b54  body 0x80166b54..0x80166c5b  size 264 B
 * body sha256 80b5cb864b355f1ee2343341e12762ae8834941ba63f2d6f9a9a2f0522781b26
 * provider record sha256 790766e2fe537e3460bcc33b1a7d389f769d2edfce1eebf5b1058a82360054ed
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166b54(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    *(uint *)(param_1 + 0x1e8) = (*(byte *)(param_1 + 5) + 1) * 0x1000000 + 0xf00;
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100)
    ;
    func_0x80077adc((*(short *)(param_1 + 500) + 1) * 0x10000 | 0x4000001,param_1 + 0x28);
  }
  else {
    iVar2 = func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),
                            *(undefined4 *)(param_1 + 0x218),0x100);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1000000;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfe;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      return;
    }
  }
  uVar1 = **(uint **)(*(int *)(param_1 + 0x250) + 0x214) >> 0x14 & 0xf;
  if (uVar1 != 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x250) + 0x234) + (uint)(byte)(&DAT_80167fe3)[uVar1] * 0x178
    ;
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(iVar2 + 0x4c);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar2 + 0x54);
  }
  return;
}
