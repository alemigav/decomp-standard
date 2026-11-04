/* FUN_80164600
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164600  body 0x80164600..0x80164777  size 376 B
 * body sha256 86719e5c03b409924bfa5846b0f9da9843a2a588e85edde8c529013feb60b615
 * provider record sha256 8d915cf1adb2cabbd21898c4fee3a53713b77b6a8d48881febd8cff0ce9d8382
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164600(uint *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      iVar2 = func_0x80036c68(param_1,0xe,0,0);
      if (iVar2 != 0) {
        param_1[1] = 0x1010000;
        *param_1 = *param_1 & 0xfffffbf7;
      }
      if (*(char *)((int)param_1 + 0x1e9) != '3') {
        return;
      }
      if (*(short *)(param_1 + 0x7d) == 0) {
        param_1[10] = 0xffff9bce;
        param_1[0xb] = 0xffffc7bf;
        param_1[0xc] = 0xffffef98;
        *(undefined2 *)((int)param_1 + 0x66) = 0xc20;
        *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xbfff;
        return;
      }
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -1;
      param_1[0xb] = param_1[0xb] - 1000;
      if (*(short *)(param_1 + 0x7d) == 0) {
        *(undefined2 *)((int)param_1 + 0x272) = 1;
      }
      *(undefined1 *)((int)param_1 + 0x1e9) = 0x32;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x7d) = 10;
    *(undefined2 *)(param_1 + 0x9c) = 0;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    *param_1 = *param_1 | 0x408;
  }
  if (*(short *)(param_1 + 0x9c) != 0) {
    _DAT_800e110c = _DAT_800e110c | 0x100;
    param_1[10] = 0xffffa2c5;
    param_1[0xb] = 0xffffd378;
    param_1[0xc] = 0x1f8;
    *(undefined2 *)((int)param_1 + 0x66) = 0x800;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  return;
}
