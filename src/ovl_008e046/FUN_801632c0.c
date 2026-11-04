/* FUN_801632c0
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801632c0  body 0x801632c0..0x8016342b  size 364 B
 * body sha256 a200bebad10984bf38baab68611c082af45e7fe10308d3366f34f1b74d9efda7
 * provider record sha256 f63743734e7d06e163399631251dd728049a1e04f000bc587b98453e76b87676
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801632c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 0x1e8) = 0x4000f00;
        *(undefined2 *)(param_1 + 6) = 0x300;
      }
      else if (bVar1 != 3) {
        return;
      }
      *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
      func_0x8008a994(param_1,param_2,param_3,0x100);
      if (*(byte *)(param_1 + 7) < 5) {
        return;
      }
      *(undefined4 *)(param_1 + 4) = 0x10f0000;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
    *(undefined1 *)(param_1 + 0x2ce) = 3;
    *(undefined1 *)(param_1 + 6) = 1;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) & 0xfffd;
  }
  func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                  *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x60);
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar2 = (int)*(short *)(param_1 + 0x1e0);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 3;
  }
  iVar4 = (int)*(short *)(param_1 + 0x1e4);
  *(short *)(param_1 + 0x1e0) = (short)(iVar2 >> 2);
  if (iVar4 < 0) {
    iVar4 = iVar4 + 3;
  }
  *(short *)(param_1 + 0x1e4) = (short)(iVar4 >> 2);
  cVar3 = func_0x8008a994(param_1,param_2,param_3,0x100);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
  func_0x80032c6c(param_1,0,0);
  return;
}
