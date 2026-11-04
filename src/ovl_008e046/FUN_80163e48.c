/* FUN_80163e48
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80163e48  body 0x80163e48..0x80164013  size 460 B
 * body sha256 dd3217933800dd8e46a431dc5451d67d7840745c72c61dde1b7c92f1a25f91a4
 * provider record sha256 a937e882f645617c9bdd3dbe708b4a5c9bf0ea08cd874961bb29e6f11baf182f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163e48(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = *(byte *)(param_1 + 6);
  if (bVar3 != 1) {
    if (1 < bVar3) {
      if (bVar3 == 2) {
        if (*(uint *)(param_1 + 0x28c) < 0x9c4) {
          *(undefined4 *)(param_1 + 4) = 0x10f0000;
        }
        func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                        *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x40);
        func_0x800334c8(param_1,param_2,param_3,0);
        iVar1 = func_0x8008a994(param_1,param_2,param_3,0x1000);
        if (iVar1 != 0) {
          if (8000 < *(uint *)(param_1 + 0x28c)) {
            *(undefined1 *)(param_1 + 0x2b5) = 1;
            *(undefined4 *)(param_1 + 4) = 0x1000000;
            return;
          }
          if (*(uint *)(param_1 + 0x28c) < 2000) {
            *(undefined4 *)(param_1 + 4) = 0x10f0000;
          }
          else {
            uVar2 = func_0x80033604(param_1);
            if ((uVar2 & 3) == 0) {
              *(undefined4 *)(param_1 + 0x1e8) = 0;
            }
            *(undefined2 *)(param_1 + 6) = 0x200;
          }
        }
        func_0x80032c6c(param_1,0,0);
        return;
      }
      if (bVar3 != 3) {
        return;
      }
      bVar3 = *(char *)(param_1 + 7) + 1;
      *(byte *)(param_1 + 7) = bVar3;
      if (bVar3 < 6) {
        return;
      }
      *(undefined4 *)(param_1 + 0x1e8) = 0;
      *(undefined2 *)(param_1 + 6) = 0x200;
      return;
    }
    if (bVar3 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x6050300;
    *(undefined1 *)(param_1 + 0x2ce) = 4;
    *(undefined2 *)(param_1 + 6) = 0x100;
    *(ushort *)(param_1 + 0x2c8) = *(ushort *)(param_1 + 0x2c8) | 2;
  }
  iVar1 = func_0x8008a994(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  func_0x80032dbc(param_1,*(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x28),
                  *(undefined4 *)(*(int *)(param_1 + 0x2c4) + 0x30),0x40);
  return;
}
