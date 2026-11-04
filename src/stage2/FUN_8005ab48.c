/* FUN_8005ab48
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005ab48  body 0x8005ab48..0x8005b4d7  size 2448 B
 * body sha256 67319ef1609d05113c15c4eed9664eed43427d0e75d9f501aaba298e0bb37b59
 * provider record sha256 9137caf4b50c9ee8a8b4de0f497ffc5fa112fd9341e6219c7fda128a8962c7a8
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
uint * FUN_8005ab48(int param_1,uint param_2,int *param_3)

{
  byte bVar4;
  int iVar1;
  int iVar2;
  short sVar3;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint unaff_s7;
  uint *puVar11;
  uint local_70;
  undefined4 local_6c;
  uint local_68;
  uint local_60;
  uint local_58;
  int local_50;
  int local_4c;
  uint local_48;
  undefined4 *local_44;
  uint *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  local_38 = 0x7fffffff;
  local_48 = 0;
  puVar11 = (uint *)0x0;
  if (DAT_800e1126 != '\0') {
    if (*(char *)(param_1 + 0x288) == '\0') {
      bVar4 = *(char *)(param_1 + 0x289) + 1;
      *(byte *)(param_1 + 0x289) = bVar4;
      *(undefined1 *)(param_1 + 0x288) = *(undefined1 *)((uint)bVar4 * 2 + param_3[1] + 1);
    }
    uVar6 = (uint)*(byte *)((uint)*(byte *)(param_1 + 0x289) * 2 + param_3[1]);
    if (uVar6 == 0xff) {
      *(char *)(param_1 + 0x288) = *(char *)(param_1 + 0x288) + -1;
      return (uint *)0x0;
    }
    if (uVar6 == 0xfe) {
      *(undefined1 *)(param_1 + 0x289) = 0;
      *(undefined1 *)(param_1 + 0x288) = *(undefined1 *)(param_3[1] + 1);
      uVar6 = (uint)*(byte *)((uint)*(byte *)(param_1 + 0x289) * 2 + param_3[1]);
      if (uVar6 == 0xff) {
        return (uint *)0x0;
      }
    }
    if (*(char *)(param_1 + 0x288) == -1) {
      return (uint *)0x0;
    }
    local_44 = &DAT_800e13f0;
    iVar10 = *param_3 + uVar6 * 0x1c;
    local_2c = *(int *)(param_1 + 0x234) + (uint)*(byte *)(param_1 + 0x25d) * 0x178 + 0x4c;
    do {
      puVar9 = (uint *)*local_44;
      puVar7 = local_44 + 1;
      if (((*puVar9 & 1) == 0) || (*(char *)((int)puVar9 + 0x26f) != '\0')) {
LAB_8005ad4c:
        local_44 = puVar7;
      }
      else {
        if (-1 < *(short *)((int)puVar9 + 0x1f2)) {
          if ((*(ushort *)((int)puVar9 + 0x1aa) & 0xc000) == 0) {
            local_70 = puVar9[0x48];
            local_6c = *(undefined4 *)
                        ((uint)*(byte *)((int)puVar9 + 0x25d) * 0x178 + puVar9[0x8d] + 0x50);
            local_68 = puVar9[0x4a];
            iVar1 = FUN_8006ab40(local_2c,&local_70,0x80,1);
            uVar6 = 0;
            if (iVar1 == 0) {
              local_30 = (uint)*(ushort *)((int)puVar9 + 0x136);
              sVar3 = (short)((int)local_30 >> 2);
              *(short *)(iVar10 + 10) = *(short *)(iVar10 + 10) + sVar3;
              *(short *)(iVar10 + 0x1a) = *(short *)(iVar10 + 0x1a) + sVar3;
              *(short *)(iVar10 + 0x12) = *(short *)(iVar10 + 0x12) + sVar3;
              *(short *)(iVar10 + 8) =
                   *(short *)(iVar10 + 8) + (*(short *)((int)puVar9 + 0x28a) >> 2);
              local_60 = puVar9[10];
              local_58 = puVar9[0xc];
              puVar9[0xc] = puVar9[0x4a];
              puVar9[10] = puVar9[0x48];
              *(ushort *)(puVar9 + 0x9b) = *(ushort *)(puVar9 + 0x9b) & 0xff00;
              local_40 = (uint *)((&PTR_DAT_80110538)[*(byte *)(puVar9 + 2) - 0x10] +
                                 (param_2 >> 0x10) * 0x14);
              uVar5 = *puVar9 >> 0x1a & 7;
              iVar1 = puVar9[0xb] - *(int *)(param_1 + 0x2c);
              if (uVar5 != 0) {
                if ((*(char *)(iVar10 + 1) != '\0') &&
                   (iVar2 = FUN_8005b4d8(local_40,*(char *)(iVar10 + 1),&local_50,&local_4c),
                   (uint)(iVar1 - local_50) <= (uint)(local_4c - local_50))) {
                  bVar4 = *(byte *)(iVar10 + 1);
                  iVar8 = 6;
                  if (local_4c + iVar2 * 2 <= iVar1) {
                    iVar8 = 3;
                  }
                  if (local_4c + iVar2 <= iVar1) {
                    iVar8 = 0;
                  }
                  iVar2 = FUN_8005b69c(param_1 + 0x10,puVar9 + 4,iVar10 + 4);
                  if (iVar2 != 0) {
                    iVar2 = (uint)((bVar4 & 8) != 0) * 9;
                    if (((byte)(&DAT_80110e62)[iVar8 + iVar2] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e62)[iVar8 + iVar2] >> 1);
                      uVar6 = unaff_s7 * 8 + 1;
                    }
                    if (((byte)(&DAT_80110e61)[iVar8 + iVar2] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e61)[iVar8 + iVar2] >> 1);
                      uVar6 = unaff_s7 * 8 + 1;
                    }
                    if (((byte)(&DAT_80110e60)[iVar8 + iVar2] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e60)[iVar8 + iVar2] >> 1);
                      uVar6 = unaff_s7 * 8 + 1;
                    }
                  }
                }
                if ((*(char *)(iVar10 + 2) != '\0') &&
                   (iVar2 = FUN_8005b4d8(local_40,*(char *)(iVar10 + 2),&local_50,&local_4c),
                   (uint)(iVar1 - local_50) <= (uint)(local_4c - local_50))) {
                  bVar4 = *(byte *)(iVar10 + 2);
                  iVar8 = 6;
                  if (local_4c + iVar2 * 2 <= iVar1) {
                    iVar8 = 3;
                  }
                  if (local_4c + iVar2 <= iVar1) {
                    iVar8 = 0;
                  }
                  iVar2 = FUN_8005b69c(param_1 + 0x10,puVar9 + 4,iVar10 + 0xc);
                  if (iVar2 != 0) {
                    iVar2 = (uint)((bVar4 & 8) != 0) * 9;
                    uVar6 = 0;
                    if (((byte)(&DAT_80110e62)[iVar8 + iVar2] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e62)[iVar8 + iVar2] >> 1);
                      uVar6 = unaff_s7 * 8 + 2;
                    }
                    if (((byte)(&DAT_80110e61)[iVar8 + iVar2] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e61)[iVar8 + iVar2] >> 1);
                      uVar6 = unaff_s7 * 8 + 2;
                    }
                    if (((byte)(&DAT_80110e60)[iVar8 + iVar2] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e60)[iVar8 + iVar2] >> 1);
                      uVar6 = unaff_s7 * 8 + 2;
                    }
                  }
                }
                if ((*(char *)(iVar10 + 3) != '\0') &&
                   (iVar2 = FUN_8005b4d8(local_40,*(char *)(iVar10 + 3),&local_50,&local_4c),
                   (uint)(iVar1 - local_50) <= (uint)(local_4c - local_50))) {
                  bVar4 = *(byte *)(iVar10 + 3);
                  iVar8 = 6;
                  if (local_4c + iVar2 * 2 <= iVar1) {
                    iVar8 = 3;
                  }
                  if (local_4c + iVar2 <= iVar1) {
                    iVar8 = 0;
                  }
                  iVar1 = FUN_8005b69c(param_1 + 0x10,puVar9 + 4,iVar10 + 0x14);
                  if (iVar1 != 0) {
                    iVar1 = (uint)((bVar4 & 8) != 0) * 9;
                    uVar6 = 0;
                    if (((byte)(&DAT_80110e62)[iVar8 + iVar1] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e62)[iVar8 + iVar1] >> 1);
                      uVar6 = unaff_s7 * 8 + 4;
                    }
                    if (((byte)(&DAT_80110e61)[iVar8 + iVar1] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e61)[iVar8 + iVar1] >> 1);
                      uVar6 = unaff_s7 * 8 + 4;
                    }
                    if (((byte)(&DAT_80110e60)[iVar8 + iVar1] & uVar5) != 0) {
                      unaff_s7 = (uint)((byte)(&DAT_80110e60)[iVar8 + iVar1] >> 1);
                      uVar6 = unaff_s7 * 8 + 4;
                    }
                  }
                }
                *(ushort *)(puVar9 + 0x9b) = *(ushort *)(puVar9 + 0x9b) | (ushort)uVar6;
                if ((uVar6 != 0) &&
                   (iVar1 = *(int *)(param_1 + 0x28) - puVar9[10],
                   iVar2 = *(int *)(param_1 + 0x30) - puVar9[0xc],
                   uVar5 = FUN_80040bb4(iVar1 * iVar1 + iVar2 * iVar2), uVar5 < local_38)) {
                  local_3c = local_40;
                  puVar11 = puVar9;
                  local_48 = uVar6;
                  local_38 = uVar5;
                  local_34 = unaff_s7;
                }
              }
              sVar3 = (short)((int)local_30 >> 2);
              *(short *)(iVar10 + 10) = *(short *)(iVar10 + 10) - sVar3;
              *(short *)(iVar10 + 0x1a) = *(short *)(iVar10 + 0x1a) - sVar3;
              *(short *)(iVar10 + 0x12) = *(short *)(iVar10 + 0x12) - sVar3;
              *(short *)(iVar10 + 8) =
                   *(short *)(iVar10 + 8) - (*(short *)((int)puVar9 + 0x28a) >> 2);
              puVar9[10] = local_60;
              local_44 = local_44 + 1;
              puVar9[0xc] = local_58;
              goto LAB_8005b250;
            }
          }
          puVar7 = local_44 + 1;
          goto LAB_8005ad4c;
        }
        local_44 = puVar7;
      }
LAB_8005b250:
    } while (local_44 != DAT_800df93c);
    *(char *)(param_1 + 0x288) = *(char *)(param_1 + 0x288) + -1;
    if ((param_2 & 0x8000) == 0) {
      if (puVar11 == (uint *)0x0) {
        return (uint *)0xff;
      }
      uVar6 = (uint)((local_48 & 2) != 0);
      if ((local_48 & 4) != 0) {
        uVar6 = 2;
      }
      uVar5 = puVar11[1];
      *(ushort *)((int)puVar11 + 0x1f2) =
           *(short *)((int)puVar11 + 0x1f2) - ((ushort)(*local_3c >> uVar6 * 10) & 0x3ff);
      puVar11[1] = 0x2000000;
      puVar11[0xa6] = uVar5;
      if (*(short *)((int)puVar11 + 0x1f2) < 0) {
        puVar11[1] = 0x3000000;
      }
      if ((local_34 == 0) &&
         (iVar10 = (uint)*(byte *)((int)puVar11 + 0x1ef) - (local_3c[1] >> uVar6 * 3 & 7),
         *(char *)((int)puVar11 + 0x1ef) = (char)iVar10, iVar10 * 0x1000000 < 0)) {
        *(undefined1 *)((int)puVar11 + 0x1ef) = 0xff;
      }
      if ((local_34 == 1) &&
         (iVar10 = (uint)*(byte *)((int)puVar11 + 0x1ee) - (local_3c[1] >> uVar6 * 3 & 7),
         *(char *)((int)puVar11 + 0x1ee) = (char)iVar10, iVar10 * 0x1000000 < 0)) {
        *(undefined1 *)((int)puVar11 + 0x1ee) = 0xff;
      }
      if ((local_34 == 2) &&
         (iVar10 = (uint)*(byte *)((int)puVar11 + 0x1ed) - (local_3c[1] >> uVar6 * 3 & 7),
         *(char *)((int)puVar11 + 0x1ed) = (char)iVar10, iVar10 * 0x1000000 < 0)) {
        *(undefined1 *)((int)puVar11 + 0x1ed) = 0xff;
      }
      sVar3 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                           (int)*(short *)((int)puVar11 + 0x2a),(int)*(short *)((int)puVar11 + 0x32)
                          );
      iVar10 = (int)sVar3 - (int)*(short *)((int)puVar11 + 0x66);
      if ((iVar10 + 0x400U & 0xfff) < 0x800) {
        *(ushort *)(puVar11 + 0x9b) = *(ushort *)(puVar11 + 0x9b) | 0x20;
      }
      if ((iVar10 + 0x600U & 0xfff) < 0x400) {
        *(ushort *)(puVar11 + 0x9b) = *(ushort *)(puVar11 + 0x9b) | 0x40;
      }
      if ((iVar10 - 0x200U & 0xfff) < 0x400) {
        *(ushort *)(puVar11 + 0x9b) = *(ushort *)(puVar11 + 0x9b) | 0x80;
      }
      *(char *)((int)puVar11 + 0x26e) = (char)uVar6 * '\x03' + (char)local_34;
      bVar4 = *(byte *)((int)puVar11 + 0x26f) & 0x80;
      *(char *)((int)puVar11 + 5) = (char)(param_2 >> 0x10) + '\x01';
      *(byte *)((int)puVar11 + 0x26f) = bVar4;
      *(byte *)((int)puVar11 + 0x26f) = bVar4 | (byte)(local_3c[1] >> (uVar6 * 7 + 9 & 0x1f)) & 0x7f
      ;
      return (uint *)(unaff_s7 + 1);
    }
  }
  return puVar11;
}
