/* FUN_800609e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800609e0  body 0x800609e0..0x80060f77  size 1432 B
 * body sha256 671c5197bc9a68b4c1726e648870d7ff5c1fd301a67fbcd5fdcb1475069b961f
 * provider record sha256 9f006daca5f2baa4611f50573d98633d77400ffc112cbb0262d3ca4920533afd
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_800609e0(int param_1,short param_2,int param_3,uint param_4)

{
  byte bVar1;
  short sVar2;
  byte bVar4;
  uint uVar3;
  int iVar5;
  undefined *puVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
  
  if (DAT_800e1126 != '\0') {
    puVar9 = &DAT_800e13f0;
    bVar1 = (byte)(param_4 >> 0x18);
    puVar8 = (uint *)0x0;
    do {
      puVar7 = (uint *)*puVar9;
      if (((((*puVar7 & 1) != 0) && (*(char *)((int)puVar7 + 0x26f) == '\0')) &&
          (-1 < *(short *)((int)puVar7 + 0x1f2))) &&
         ((*(ushort *)((int)puVar7 + 0x1aa) & 0xc000) == 0)) {
        *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) & 0xff00;
        if ((puVar7[0xb] + (int)*(short *)(puVar7 + 0x4d) + 100 +
            (uint)*(ushort *)((int)puVar7 + 0x13a)) - *(int *)(param_1 + 4) <
            (*(ushort *)((int)puVar7 + 0x13a) + 100) * 2) {
          *(short *)(param_3 + 6) = *(short *)(param_3 + 6) + (*(short *)((int)puVar7 + 0x28a) >> 2)
          ;
          *(short *)(param_3 + 4) = *(short *)(param_3 + 4) + (*(short *)((int)puVar7 + 0x28a) >> 2)
          ;
          iVar5 = FUN_8005b930(param_1,(int)param_2,puVar7 + 0x48,param_3);
          if (iVar5 == 0) {
            *(short *)(param_3 + 6) =
                 *(short *)(param_3 + 6) - (*(short *)((int)puVar7 + 0x28a) >> 2);
            *(short *)(param_3 + 4) =
                 *(short *)(param_3 + 4) - (*(short *)((int)puVar7 + 0x28a) >> 2);
          }
          else {
            *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) | 1;
            if ((param_4 & 0x10000) == 0) goto LAB_80060d50;
            puVar6 = (&PTR_DAT_80110538)[*(byte *)(puVar7 + 2) - 0x10];
            *(ushort *)((int)puVar7 + 0x1f2) =
                 *(short *)((int)puVar7 + 0x1f2) -
                 ((ushort)(*(uint *)(puVar6 + (param_4 & 0xffff) * 0x14 + -0x14) >>
                          ((param_4 >> 0x1c) * 10 & 0x1f)) & 0x3ff);
            if (puVar7[1] != 0x20c0000) {
              puVar7[0xa6] = puVar7[1];
            }
            puVar7[1] = 0x2000000;
            if (*(short *)((int)puVar7 + 0x1f2) < 0) {
              puVar7[1] = 0x3000000;
            }
            *(undefined1 *)((int)puVar7 + 0x26e) = 1;
            if ((param_4 & 0x20000) != 0) {
              iVar5 = (int)((uint)*(ushort *)(puVar7 + 0x4d) << 0x10) >> 0x11;
              if ((int)(puVar7[0xb] + iVar5) < *(int *)(param_1 + 4)) {
                *(undefined1 *)((int)puVar7 + 0x26e) = 0;
              }
              if (((*puVar7 & 0x10000000) != 0) &&
                 (*(int *)(param_1 + 4) < (int)(puVar7[0xb] + iVar5 * 3))) {
                *(undefined1 *)((int)puVar7 + 0x26e) = 2;
              }
            }
            *(char *)((int)puVar7 + 5) = (char)param_4;
            bVar4 = *(byte *)((int)puVar7 + 0x26f) & 0x80;
            *(byte *)((int)puVar7 + 0x26e) = *(char *)((int)puVar7 + 0x26e) + (bVar1 >> 4) * '\x03';
            *(byte *)((int)puVar7 + 0x26f) = bVar4;
            *(byte *)((int)puVar7 + 0x26f) =
                 bVar4 | (byte)(*(uint *)((int)(puVar6 + (param_4 & 0xffff) * 0x14 + -0x14) + 4) >>
                               9) & 0x7f;
            sVar2 = FUN_80032d14((int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 10),
                                 (int)*(short *)((int)puVar7 + 0x2a),
                                 (int)*(short *)((int)puVar7 + 0x32));
            iVar5 = (int)sVar2 - (int)*(short *)((int)puVar7 + 0x66);
            if ((iVar5 + 0x400U & 0xfff) < 0x800) {
              *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) | 0x20;
            }
            if ((iVar5 + 0x600U & 0xfff) < 0x400) {
              *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) | 0x40;
            }
            puVar8 = puVar7;
            if ((iVar5 - 0x200U & 0xfff) < 0x400) {
              *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) | 0x80;
            }
          }
        }
      }
      puVar7 = puVar8;
      puVar9 = puVar9 + 1;
      puVar8 = puVar7;
    } while (puVar9 != DAT_800df93c);
    if ((param_4 & 0x10000) != 0) goto LAB_80060f48;
LAB_80060d50:
    if (puVar7 != (uint *)0x0) {
      puVar6 = (&PTR_DAT_80110538)[*(byte *)(puVar7 + 2) - 0x10];
      uVar3 = puVar7[1];
      *(ushort *)((int)puVar7 + 0x1f2) =
           *(short *)((int)puVar7 + 0x1f2) -
           ((ushort)(*(uint *)(puVar6 + (param_4 & 0xffff) * 0x14 + -0x14) >>
                    ((param_4 >> 0x1c) * 10 & 0x1f)) & 0x3ff);
      if ((uVar3 != 0x20c0000) && (uVar3 != 0x30c00000)) {
        puVar7[0xa6] = uVar3;
      }
      puVar7[1] = 0x2000000;
      if (*(short *)((int)puVar7 + 0x1f2) < 0) {
        puVar7[1] = 0x3000000;
      }
      *(undefined1 *)((int)puVar7 + 0x26e) = 1;
      if ((param_4 & 0x20000) != 0) {
        iVar5 = (int)((uint)*(ushort *)(puVar7 + 0x4d) << 0x10) >> 0x11;
        if ((int)(puVar7[0xb] + iVar5) < *(int *)(param_1 + 4)) {
          *(undefined1 *)((int)puVar7 + 0x26e) = 0;
        }
        if (((*puVar7 & 0x10000000) != 0) &&
           (*(int *)(param_1 + 4) < (int)(puVar7[0xb] + iVar5 * 3))) {
          *(undefined1 *)((int)puVar7 + 0x26e) = 2;
        }
      }
      if (((param_4 & 0x40000) != 0) &&
         (*(char *)((int)puVar7 + 0x1a2) == *(char *)(DAT_800df938 + 0x1a2))) {
        *(undefined1 *)((int)puVar7 + 0x26e) = 0;
      }
      *(char *)((int)puVar7 + 5) = (char)param_4;
      bVar4 = *(byte *)((int)puVar7 + 0x26f) & 0x80;
      *(byte *)((int)puVar7 + 0x26e) = *(char *)((int)puVar7 + 0x26e) + (bVar1 >> 4) * '\x03';
      *(byte *)((int)puVar7 + 0x26f) = bVar4;
      *(byte *)((int)puVar7 + 0x26f) =
           bVar4 | (byte)(*(uint *)((int)(puVar6 + (param_4 & 0xffff) * 0x14 + -0x14) + 4) >> 9) &
                   0x7f;
      sVar2 = FUN_80032d14((int)*(short *)(param_1 + 2),(int)*(short *)(param_1 + 10),
                           (int)*(short *)((int)puVar7 + 0x2a),(int)*(short *)((int)puVar7 + 0x32));
      iVar5 = (int)sVar2 - (int)*(short *)((int)puVar7 + 0x66);
      if ((iVar5 + 0x400U & 0xfff) < 0x800) {
        *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) | 0x20;
      }
      if ((iVar5 + 0x600U & 0xfff) < 0x400) {
        *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) | 0x40;
      }
      if (0x3ff < (iVar5 - 0x200U & 0xfff)) {
        return puVar7;
      }
      *(ushort *)(puVar7 + 0x9b) = *(ushort *)(puVar7 + 0x9b) | 0x80;
      goto LAB_80060f48;
    }
  }
  puVar7 = (uint *)0x0;
LAB_80060f48:
  return puVar7;
}
