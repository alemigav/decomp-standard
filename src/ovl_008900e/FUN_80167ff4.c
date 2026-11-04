/* FUN_80167ff4
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80167ff4  body 0x80167ff4..0x801680f3  size 256 B
 * body sha256 2a5e5e543129fb1f9b3135e8050ba89b1621dd7fa66dcb087852748250b4614e
 * provider record sha256 1ca8be5b1f7b944b482c6271b88e78236c0ef832b505592035bf6a46c16162f3
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167ff4(uint *param_1)

{
  char cVar2;
  int iVar1;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    func_0x80077d18(8,param_1);
    FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,0);
    *param_1 = *param_1 | 2;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 1:
    cVar2 = func_0x80036d14(param_1,0x1c,0,0);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    if (-1000 < *(short *)((int)param_1 + 0x2d6)) {
      *(short *)((int)param_1 + 0x2d6) = *(short *)((int)param_1 + 0x2d6) + -0x32;
    }
    break;
  case 2:
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 3:
    iVar1 = func_0x80036be4(param_1,0xb,0xf,0);
    if (iVar1 != 0) {
      *(undefined1 *)((int)param_1 + 0x2b7) = 1;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
  }
  return;
}
