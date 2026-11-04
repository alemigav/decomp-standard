/* FUN_80166368
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166368  body 0x80166368..0x8016656b  size 516 B
 * body sha256 5325a728d42a9874c5c5ac5966186435d7267712ae92449638373dba70757c71
 * provider record sha256 909f2b4fd9cec4f8dd9aa2d9e7c67430c4f1436d903a7c119f97f6fa354c4bd3
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166368(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar3;
  int iVar2;
  short sVar4;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if (*(short *)(param_1 + 0x1f2) < 0) {
          *(undefined1 *)(param_1 + 7) = 0;
          *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
          return;
        }
        *(undefined4 *)(param_1 + 0x1e8) = 0x5000f00;
        *(undefined1 *)(param_1 + 7) = 3;
        *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
      }
      else if (bVar1 != 3) {
        return;
      }
      iVar2 = func_0x8008a994(param_1,param_2,param_3,0x10100);
      if (iVar2 == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 0x2ce) = 3;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      FUN_80165a84();
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80077d18(7,param_1);
    FUN_80162ba4(param_1,&UNK_801673e8 + (uint)*(byte *)(param_1 + 0x2cb) * 8,1);
    *(undefined2 *)(param_1 + 0x1e0) = 100;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    func_0x800837d0((int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x66),param_1 + 0x1e0,
                    param_1 + 0x1e0);
    func_0x80032ef4(param_1,(int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x66),0x80);
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined4 *)(param_1 + 0x1e8) = 0xa000300;
    *(undefined1 *)(param_1 + 7) = 1;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
  }
  cVar3 = func_0x8008a994(param_1,param_2,param_3,0x400);
  sVar4 = *(short *)(param_1 + 500) + 1;
  *(short *)(param_1 + 500) = sVar4;
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar3;
  if (sVar4 == 4) {
    *(undefined2 *)(param_1 + 0x1e0) = 0x32;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    func_0x800837d0((int)*(short *)(*(int *)(param_1 + 0x2c4) + 0x66),param_1 + 0x1e0,
                    param_1 + 0x1e0);
  }
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)*(short *)(param_1 + 0x1e0);
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)*(short *)(param_1 + 0x1e4);
  return;
}
