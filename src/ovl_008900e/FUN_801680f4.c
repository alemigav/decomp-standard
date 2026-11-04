/* FUN_801680f4
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x801680f4  body 0x801680f4..0x801681d7  size 228 B
 * body sha256 116986f1274305080a4829b51987d6dfbfd89f42828bbe6cc0049a1e486670d5
 * provider record sha256 f43bd8d3d18849378382f85487247fa6de971b3b4bbd98b166814c2f9efaad88
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801680f4(uint *param_1)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined1 *)((int)param_1 + 0x2b7) = 1;
        *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80077d18(8,param_1);
    FUN_80162ba4(param_1,&UNK_80168bf4 + (uint)*(byte *)((int)param_1 + 0x2cb) * 8,1);
    *param_1 = *param_1 | 2;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  cVar2 = func_0x80036d14(param_1,0x1d,0xf,0);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  if (*(short *)((int)param_1 + 0x2d6) < -100) {
    *(short *)((int)param_1 + 0x2d6) = *(short *)((int)param_1 + 0x2d6) + 0x19;
  }
  return;
}
