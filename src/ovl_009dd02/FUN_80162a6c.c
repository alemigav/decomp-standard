/* FUN_80162a6c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162a6c  body 0x80162a6c..0x80162e27  size 956 B
 * body sha256 ca9f992e8b8b2d02dd4c976390eab543228ff34fadbfc3a241278f1270c0bc03
 * provider record sha256 d7c1f57a31780be6accb0af7d36b70f99345d9da708fc837e2c2699239d1ade7
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162a6c(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined1 *puVar4;
  uint uVar5;
  int local_28 [2];
  
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    puVar4 = &DAT_800e1130;
  }
  else {
    puVar4 = _DAT_800e13ec;
  }
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    uVar5 = *(uint *)(param_1 + 0x28c);
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x290) & 0x3fffffff;
  }
  if (-1 < *(short *)(puVar4 + 0x1f2)) {
    if ((_DAT_800e1128 & 0x80) == 0) {
      sVar1 = *(short *)(*(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x5a
                        );
      if ((((*(char *)(param_1 + 0x2b4) == '\0') && ((_DAT_800e1128 & 0x20) != 0)) &&
          ((*(ushort *)(param_1 + 0x2d4) & 0x8000) == 0)) && (*(char *)(param_1 + 0x2cd) == '\0')) {
        sVar1 = func_0x80032e74(param_1,*(undefined4 *)(puVar4 + 0x28),
                                *(undefined4 *)(puVar4 + 0x30),
                                (int)(((uint)*(byte *)(param_1 + 0x2cd) * 0x800 + 0x100) * 0x10000)
                                >> 0x10);
        if ((((int)uVar5 < 0xa8d) && (sVar1 == 0)) && (*(short *)(puVar4 + 0x1f2) == 0)) {
          *(undefined1 *)(param_1 + 5) = 6;
          *(undefined2 *)(param_1 + 6) = 0;
          *(undefined2 *)(puVar4 + 0x1f2) = 0xffff;
          *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
        }
      }
      else if (((*(char *)(param_1 + 0x2b5) == '\0') ||
               (*(char *)(*(int *)(param_1 + 0x2d0) + 0x2cd) != '\0')) ||
              ((_DAT_800e1128 & 0x20) == 0)) {
        if (*(char *)(param_1 + 0x2bd) == '\0') {
          sVar2 = FUN_80166f84(param_1,0xb,1,local_28);
          sVar3 = FUN_80166f84(param_1,0xb,0x200,local_28);
          if (((local_28[0] < 0x5dd) && (sVar3 == 0)) &&
             ((-1 < (0x800 - sVar1) * (int)sVar2 &&
              ((((*(ushort *)(param_1 + 0x2d4) & 0x8000) == 0 &&
                (*(char *)(param_1 + 0x2b4) == '\0')) && ((puVar4[0x26f] & 0x80) == 0)))))) {
            *(undefined1 *)(param_1 + 5) = 10;
            *(undefined2 *)(param_1 + 6) = 0;
            _DAT_800e1128 = _DAT_800e1128 | 0x80;
            func_0x80052bd0(3,0);
            func_0x80052c6c(6,0x96,0);
            return;
          }
        }
        *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar1;
        sVar2 = FUN_80166d64(param_1,*(undefined4 *)(puVar4 + 0x28),*(undefined4 *)(puVar4 + 0x30),
                             0x100);
        *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) - sVar1;
        if ((((int)uVar5 < 0xfa1) && (sVar2 == 0)) &&
           (((*(char *)(param_1 + 700) == '\0' &&
             (((_DAT_800e1128 & 0x40) == 0 && (puVar4[4] == '\x01')))) && (puVar4[5] != '\x02')))) {
          *(undefined1 *)(param_1 + 5) = 4;
          *(undefined2 *)(param_1 + 6) = 0;
        }
        else {
          *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar1;
          sVar2 = FUN_80166d64(param_1,*(undefined4 *)(puVar4 + 0x28),*(undefined4 *)(puVar4 + 0x30)
                               ,0x100);
          *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) - sVar1;
          if ((((uVar5 - 4000 < 0x1389) && (sVar2 == 0)) && (*(char *)(param_1 + 0x2be) == '\0')) &&
             ((*(ushort *)(param_1 + 0x2d4) & 0x8000) == 0)) {
            *(undefined1 *)(param_1 + 5) = 5;
            *(undefined2 *)(param_1 + 6) = 0;
            *(undefined1 *)(param_1 + 0x2da) = 0;
          }
        }
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x2bd) = 0x1e;
      *(undefined1 *)(param_1 + 700) = 0x1e;
    }
  }
  return;
}
