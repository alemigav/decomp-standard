/* FUN_80162f34
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162f34  body 0x80162f34..0x80162fef  size 188 B
 * body sha256 5af08d0368d7b7835ffde4dc5d1061329b4a2ee3c7ccbf131931210d81868c63
 * provider record sha256 feddfdcd4512beb7f60fda32b8402df737f6c199698872c11394b31e88631757
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_80162f34(uint *param_1,undefined2 param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  
  if (*(byte *)((int)param_1 + 0x2b6) < *(byte *)((int)param_1 + 0x2be)) {
    puVar1 = (uint *)func_0x80031ff0(0x3b);
    puVar3 = (uint *)0x0;
    if (puVar1 != (uint *)0x0) {
      if ((*param_1 & 0x2000) == 0) {
        *(undefined2 *)((int)puVar1 + 0x1aa) = param_2;
      }
      else {
        *puVar1 = *puVar1 | 0x2000;
        *(undefined2 *)((int)puVar1 + 0x1aa) = param_2;
      }
      puVar1[10] = param_3;
      uVar2 = param_1[0xb];
      puVar1[0xc] = param_4;
      puVar1[0xb] = uVar2;
      *(char *)((int)param_1 + 0x2b6) = *(char *)((int)param_1 + 0x2b6) + '\x01';
      puVar3 = puVar1;
    }
  }
  else {
    puVar3 = (uint *)0x0;
  }
  return puVar3;
}
