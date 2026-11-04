/* FUN_80026aa8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026aa8  body 0x80026aa8..0x800270a7  size 1536 B
 * body sha256 b250770d55bc5bb8d3c5bc96b23a1109df444d368cc93044e681f3ff72e84b9c
 * provider record sha256 1f3099a5bfadfe2db832a7341749aed5c876b9c42536ac06d2379ce61142d5b1
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80026aa8(void)

{
  short sVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  if ((DAT_800e923c == '\0') || (DAT_800e923c == '\x03')) {
    sVar1 = *(short *)(DAT_800e8cac * 2 +
                      *(int *)((&PTR_PTR_8011c3b0)[DAT_800e8ca8] + DAT_800e8caa * 4));
    if ((sVar1 == 0x1112) || (sVar1 == 0x14aa)) {
      DAT_800e923c = '\x03';
    }
    else {
      DAT_800e923c = '\0';
    }
    if (DAT_800e9183 != '\0') {
      FUN_8006bccc(0);
      FUN_8006bd38(0);
      uVar3 = DAT_80112975;
      uVar2 = DAT_80112974;
      DAT_80112975 = 0;
      DAT_80112974 = 0;
      FUN_80084420();
      DAT_80112974 = uVar2;
      DAT_80112975 = uVar3;
    }
  }
  if (DAT_800e910c != -1) {
    FUN_80025ba8();
    DAT_800e9250 = DAT_800e910c;
    DAT_800e910c = -1;
  }
  if (DAT_800e9108 == 0) {
LAB_80026c78:
    if (DAT_800e9130 != 0) goto LAB_80026c88;
  }
  else {
    if ((DAT_800e9108 == DAT_800e911c) && (DAT_800e9250 == DAT_800e9124)) {
      FUN_8002607c(DAT_8010b6e8);
      DAT_800e924c = DAT_800e9108;
      DAT_800e9108 = 0;
    }
    if ((DAT_800e9108 == DAT_800e9120) && (DAT_800e9250 == DAT_800e9128)) {
      FUN_8002607c(DAT_8010b6ec);
      DAT_800e924c = DAT_800e9108;
      DAT_800e9108 = 0;
    }
    if (DAT_800e9108 == 0) goto LAB_80026c78;
LAB_80026c88:
    FUN_8006bd38(0);
    if (DAT_800e9130 != 0) {
      DAT_800e9130 = 0;
      DAT_8010b6f8 = (undefined4 *)(DAT_8010b6e8 + DAT_801137f0 * DAT_801137f4 * -2);
      DAT_8010b6fc = DAT_8010b6e4 + DAT_801137f0 * DAT_801137f4 * 2;
    }
  }
  if (DAT_800e9108 == 0) goto LAB_80027004;
  if (DAT_800e9108 == 0x1112) {
    FUN_800310b0(DAT_8010b6e8 + DAT_801137d8 * DAT_801137dc * -2,0x1113);
    FUN_800310b0(DAT_8010b6e8,DAT_800e9108);
    DAT_800e9120 = 0xffffffff;
    iVar6 = DAT_801137f0 * DAT_801137f4;
    DAT_800e911c = 0xffffffff;
LAB_80026edc:
    DAT_800e9110 = 0;
    DAT_8010b6f8 = (undefined4 *)(DAT_8010b6e8 + iVar6 * -2);
    DAT_8010b6fc = DAT_8010b6e4 + iVar6 * 2;
    FUN_8002607c();
  }
  else {
    if (DAT_800e9108 < 0x1113) {
      if (DAT_800e9108 == 0xfdb) {
        FUN_800310b0(DAT_8010b6e8,0xfdb);
        DAT_800e911c = DAT_800e9108;
        DAT_800e9124 = DAT_800e9250;
        FUN_8002607c(DAT_8010b6e8);
        if (_DAT_80000318 < 0x800000) {
          uVar5 = (uint)(DAT_801137d8 * 100) >> 3;
          puVar4 = (undefined4 *)(DAT_8010b6e8 + DAT_801137d8 * (DAT_801137dc + -0x32) * 2);
          while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
            *puVar4 = 0;
            puVar4[1] = 0x10001;
            puVar4 = puVar4 + 2;
          }
        }
        goto LAB_80026fe8;
      }
    }
    else if (DAT_800e9108 == 0x14aa) {
      FUN_800310b0(DAT_8010b6e8 + DAT_801137d8 * DAT_801137dc * -2,0x14ab);
      FUN_800310b0(DAT_8010b6e8,DAT_800e9108);
      iVar6 = DAT_801137f0 * DAT_801137f4;
      goto LAB_80026edc;
    }
    DAT_8010b6f8 = (undefined4 *)(DAT_8010b6e4 + DAT_801137f0 * DAT_801137f4 * 2);
    DAT_8010b6fc = DAT_8010b6e8 + DAT_801137f0 * DAT_801137f4 * -2;
    if (DAT_800e912c == 0) {
      FUN_800310b0(DAT_8010b6e8,DAT_800e9108);
      DAT_800e911c = DAT_800e9108;
      DAT_800e9124 = DAT_800e9250;
      iVar6 = DAT_8010b6e8;
    }
    else {
      FUN_800310b0(DAT_8010b6ec,DAT_800e9108);
      DAT_800e9120 = DAT_800e9108;
      DAT_800e9128 = DAT_800e9250;
      iVar6 = DAT_8010b6ec;
    }
    FUN_8002607c(iVar6);
    if (DAT_8010b6ec != 0) {
      DAT_800e912c = DAT_800e912c ^ 1;
    }
  }
LAB_80026fe8:
  DAT_800e924c = DAT_800e9108;
  DAT_800c4f60 = 1;
  DAT_800e9108 = 0;
LAB_80027004:
  if (DAT_800e9110 != 0) {
    FUN_8006bccc(0);
    uVar5 = (DAT_801137f0 * DAT_801137f4 & 0x7fffffffU) >> 2;
    puVar4 = DAT_8010b6f8;
    while (uVar5 = uVar5 - 1, uVar5 != 0xffffffff) {
      *puVar4 = 0xfffdfffd;
      puVar4[1] = 0xfffdfffd;
      puVar4 = puVar4 + 2;
    }
    FUN_80062cfc(1);
    DAT_800e9110 = 0;
  }
  return;
}
